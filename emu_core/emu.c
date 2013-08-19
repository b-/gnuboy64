#include "gnuboy.h"
#include "defs.h"
#include "regs.h"
#include "hw.h"
#include "cpu.h"
#include "sound.h"
#include "mem.h"
#include "lcd.h"
#include "rtc.h"
#include "pcm.h"

//#include "rc.h"

#include "hw.h"
#include "../pcm_ring_buf.h"

//static int framelen = 16743;
//static int framecount;

byte g_emu_running = 0;
/*rcvar_t emu_exports[] =
{
	RCV_INT("framelen", &framelen),
	RCV_INT("framecount", &framecount),
	RCV_END
};*/







void emu_init()
{
	g_emu_running = 0;
}


/*
 * emu_reset is called to initialize the state of the emulated
 * system. It should set cpu registers, hardware registers, etc. to
 * their appropriate values at powerup time.
 */

void emu_reset()
{
	hw_reset();
	lcd_reset();
	cpu_reset();
	mbc_reset();
	sound_reset();
	pcm_rbuf_reset();
	g_emu_running = 0;
}




/* emu_step()
	make CPU catch up with LCDC
*/
void emu_step()
{

	cpu_emulate( cpu.lcdc  );

}


/*
	Time intervals throughout the code, unless otherwise noted, are
	specified in double-speed machine cycles (2MHz), each unit
	roughly corresponds to 0.477us.
	
	For CPU each cycle takes 2dsc (0.954us) in single-speed mode
	and 1dsc (0.477us) in double speed mode.
	
	Although hardware gbc LCDC would operate at completely different
	and fixed frequency, for emulation purposes timings for it are
	also specified in double-speed cycles.
	
	line = 228 dsc (109us)
	frame (154 lines) = 35112 dsc (16.7ms)
	of which
		visible lines x144 = 32832 dsc (15.66ms)
		vblank lines x10 = 2280 dsc (1.08ms)
*/

#if 0
#include <libdragon.h>
void dbg(const char* s)
{
 
	extern display_context_t binded_display_ctx;

	unsigned int* tmp = (unsigned int*)&display_grab_framebuffer_ptr(binded_display_ctx)[16 + (168 * 320)];
	unsigned int i = 0;
	for (i = 0;i < 32;++i)tmp[i] = 0;

	graphics_draw_text(binded_display_ctx,16,168,s);
}
#endif


void emu_run()
{
	g_emu_running = 1;
 
	lcd_init();
	lcd_begin();


	extern struct hw hw;
	extern struct pcm pcm;

	pcm_rbuf_set_mode((hw.cgb) ? PCMRBUF_MODE_NON_BLOCKING : PCMRBUF_MODE_IMMEDIATE);
	
	while (g_emu_running != 0)
	{
		cpu_emulate(2280   );
 
		while ( R_LY > 0 &&  R_LY < 144) {
			emu_step();
		}

		rtc_tick();
		sound_mix();
 		pcm_submit();
		doevents();

		if (!(R_LCDC & 0x80)) {
			cpu_emulate(32832);
		}

		while ( R_LY > 0  ) {
			emu_step();
		}
	}
}

