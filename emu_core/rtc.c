
#include <stdio.h>
#include <time.h>
#include "defs.h"
#include "mem.h"
#include "rtc.h"
#include <malloc.h>
#include <string.h>
#include <libdragon.h>

struct rtc rtc;

static const int syncrtc = 0;


void rtc_latch(byte b)
{
	if ((rtc.latch ^ b) & b & 1)
	{
		rtc.regs[0] = rtc.s;
		rtc.regs[1] = rtc.m;
		rtc.regs[2] = rtc.h;
		rtc.regs[3] = rtc.d;
		rtc.regs[4] = (rtc.d>>9) | (rtc.stop<<6) | (rtc.carry<<7);
		rtc.regs[5] = 0xff;
		rtc.regs[6] = 0xff;
		rtc.regs[7] = 0xff;
	}
	rtc.latch = b;
}

void rtc_write(byte b)
{
	/* printf("write %02X: %02X (%d)\n", rtc.sel, b, b); */
	if (!(rtc.sel & 8)) return;
	switch (rtc.sel & 7)
	{
	case 0:
		rtc.s = rtc.regs[0] = b;
		if (rtc.s>=60)rtc.s -= (int)(b*(1.0/60.0));//while (rtc.s >= 60) rtc.s -= 60;
		return;
	case 1:
		rtc.m = rtc.regs[1] = b;
		if (rtc.m>=60)rtc.m -= (int)(b*(1.0/60.0));//while (rtc.m >= 60) rtc.m -= 60;
		return;
	case 2:
		rtc.h = rtc.regs[2] = b;
		if (rtc.h>=24)rtc.h -= (int)(b*(1.0/24.0));//while (rtc.h >= 24) rtc.h -= 24;
		return;
	case 3:
		rtc.regs[3] = b;
		rtc.d = (rtc.d & 0x100) | b;
		return;
	case 4:
		rtc.regs[4] = b;
		rtc.d = (rtc.d & 0xff) | ((b&1)<<9);
		rtc.stop = (b>>6)&1;
		rtc.carry = (b>>7)&1;
		return;;
	}
}

void rtc_tick()
{
	if (rtc.stop) return;
	if (++rtc.t == 60)
	{
		if (++rtc.s == 60)
		{
			if (++rtc.m == 60)
			{
				if (++rtc.h == 24)
				{
					if (++rtc.d == 365)
					{
						rtc.d = 0;
						rtc.carry = 1;
					}
					rtc.h = 0;
				}
				rtc.m = 0;
			}
			rtc.s = 0;
		}
		rtc.t = 0;
	}
}

#include <libdragon.h>

void rtc_save_internal(fs_handle_t *f)
{
	time_t rt;
    
	rt = get_ticks();

	char buf[1024];
	sprintf(buf,"%d %d %d %02d %02d %02d %02d\n%d\n",
		rtc.carry, rtc.stop, rtc.d, rtc.h, rtc.m, rtc.s, rtc.t, (int)rt);	

	data_cache_hit_writeback_invalidate(buf,sizeof(buf));
	
	fs_write(f,(const void*)buf,strlen(buf));

}

void rtc_load_internal(fs_handle_t *f)
{
	time_t rt = 0;


	char stack_buf[260];
	char* buf;

	fs_seek(f,0,FS_SEEK_SET);
	fs_seek(f,0,FS_SEEK_END);
	int len = fs_tell(f);
	fs_seek(f,0,FS_SEEK_SET);

	if (len < sizeof(stack_buf)) {
		buf = &stack_buf[0];
	} else {
		buf = (char*)malloc(len + 8);
		if (!buf) {
			return;
		}
	}
	fs_read(f,buf,len);
	buf[len] = '\0';
	data_cache_hit_writeback_invalidate(buf,len);
	sscanf(buf,"%d %d %d %02d %02d %02d %02d\n%d\n",
		&rtc.carry, &rtc.stop, &rtc.d,
		&rtc.h, &rtc.m, &rtc.s, &rtc.t, (int *)&rt);

	if (rtc.t>=60) { rtc.t = (rtc.t / 60) + (60-(rtc.t & 59)); }//while (rtc.t >= 60) rtc.t -= 60;
	if (rtc.s>=60) { rtc.s = (rtc.s / 60) + (60-(rtc.s & 59)); }//while (rtc.s >= 60) rtc.s -= 60;
	if (rtc.m>=60) { rtc.m = (rtc.m / 60) + (60-(rtc.m & 59)); }//while (rtc.m >= 60) rtc.m -= 60;
	if (rtc.h>=24) { rtc.h = (rtc.h / 24)  + (24-(rtc.h & 23)); }//while (rtc.h >= 24) rtc.h -= 24;
	if (rtc.d>=365) { rtc.d = (rtc.d / 365) + (365-(rtc.d & 364)); }//while (rtc.d >= 365) rtc.d -= 365;
	rtc.stop &= 1;
	rtc.carry &= 1;
	if (rt) rt = (get_ticks() - rt) * 60;
	//if (syncrtc) while (rt-- > 0) rtc_tick();

	if (&stack_buf[0] != buf) { free(buf); }
}

