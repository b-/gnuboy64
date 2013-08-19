/*Some mem copy hacks ~conle*/
#include "umem.h"
#include <stdint.h>
#include "../lcd_tables/u32_mask.h"
#ifndef ptrdiff_t
#define ptrdiff_t unsigned int
#endif

#define MEMCPY8(d, s) {\
	(d)[0] = (s)[0];\
	(d)[1] = (s)[1];\
	(d)[2] = (s)[2];\
	(d)[3] = (s)[3];\
	(d)[4] = (s)[4];\
	(d)[5] = (s)[5];\
	(d)[6] = (s)[6];\
	(d)[7] = (s)[7];\
}
 

#define MEMSET8(d,_v_) {\
	(d)[0] = (_v_);\
	(d)[1] = (_v_);\
	(d)[2] = (_v_);\
	(d)[3] = (_v_);\
	(d)[4] = (_v_);\
	(d)[5] = (_v_);\
	(d)[6] = (_v_);\
	(d)[7] = (_v_);\
}
void blendcpy_lte8(unsigned char *dest,const unsigned char *src, unsigned char b,int cnt)
{
	static void* blendcpy_lte8_stubs[] = {
		&&blendcpy_lte8_0,
		&&blendcpy_lte8_1,
		&&blendcpy_lte8_2,
		&&blendcpy_lte8_3,
		&&blendcpy_lte8_4,
		&&blendcpy_lte8_5,
		&&blendcpy_lte8_6,
		&&blendcpy_lte8_7,
		&&blendcpy_lte8_8,
	};

	goto *blendcpy_lte8_stubs[cnt];

	blendcpy_lte8_0:
	return;
	blendcpy_lte8_1:
		dest[0] = src[0] | b;
	return;
	blendcpy_lte8_2:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
	return;
	blendcpy_lte8_3:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
		dest[2] = src[2] | b;
	return;
	blendcpy_lte8_4:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
		dest[2] = src[2] | b;
		dest[3] = src[3] | b;
	return;
	blendcpy_lte8_5:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
		dest[2] = src[2] | b;
		dest[3] = src[3] | b;
		dest[4] = src[4] | b;
	return;
	blendcpy_lte8_6:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
		dest[2] = src[2] | b;
		dest[3] = src[3] | b;
		dest[4] = src[4] | b;
		dest[5] = src[5] | b;
	return;
	blendcpy_lte8_7:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
		dest[2] = src[2] | b;
		dest[3] = src[3] | b;
		dest[4] = src[4] | b;
		dest[5] = src[5] | b;
		dest[6] = src[6] | b;
	return;
	blendcpy_lte8_8:
		dest[0] = src[0] | b;
		dest[1] = src[1] | b;
		dest[2] = src[2] | b;
		dest[3] = src[3] | b;
		dest[4] = src[4] | b;
		dest[5] = src[5] | b;
		dest[6] = src[6] | b;
		dest[7] = src[7] | b;
	return;
}

void umemset_lte8(unsigned char *dest,unsigned char v,int cnt)
{
	static void* umemset_lte8_stubs[] = {
		&&memset_lte8_0,
		&&memset_lte8_1,
		&&memset_lte8_2,
		&&memset_lte8_3,
		&&memset_lte8_4,
		&&memset_lte8_5,
		&&memset_lte8_6,
		&&memset_lte8_7,
		&&memset_lte8_8,
	};

	goto *umemset_lte8_stubs[cnt];

	memset_lte8_0:
	return;
	memset_lte8_1:
		dest[0] = v;
	return;
	memset_lte8_2:
		dest[0] = v;
		dest[1] = v;
	return;
	memset_lte8_3:
		dest[0] = v;
		dest[1] = v;
		dest[2] = v;
	return;
	memset_lte8_4:
		dest[0] = v;
		dest[1] = v;
		dest[2] = v;
		dest[3] = v;
	return;
	memset_lte8_5:
		dest[0] = v;
		dest[1] = v;
		dest[2] = v;
		dest[3] = v;
		dest[4] = v;
	return;
	memset_lte8_6:
		dest[0] = v;
		dest[1] = v;
		dest[2] = v;
		dest[3] = v;
		dest[4] = v;
		dest[5] = v;
	return;
	memset_lte8_7:
		dest[0] = v;
		dest[1] = v;
		dest[2] = v;
		dest[3] = v;
		dest[4] = v;
		dest[5] = v;
		dest[6] = v;
	return;
	memset_lte8_8:
		dest[0] = v;
		dest[1] = v;
		dest[2] = v;
		dest[3] = v;
		dest[4] = v;
		dest[5] = v;
		dest[6] = v;
		dest[7] = v;
	return;
}

void umemcpy_lte8(unsigned char *dest,const unsigned char *src, int cnt)
{
	static void* umemcpy_lte8_stubs[] = {
		&&memcpy_lte8_0,
		&&memcpy_lte8_1,
		&&memcpy_lte8_2,
		&&memcpy_lte8_3,
		&&memcpy_lte8_4,
		&&memcpy_lte8_5,
		&&memcpy_lte8_6,
		&&memcpy_lte8_7,
		&&memcpy_lte8_8,
	};

	goto *umemcpy_lte8_stubs[cnt];

	memcpy_lte8_0:
	return;
	memcpy_lte8_1:
		dest[0] = src[0];
	return;
	memcpy_lte8_2:
		dest[0] = src[0];
		dest[1] = src[1];
	return;
	memcpy_lte8_3:
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
	return;
	memcpy_lte8_4:
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
		dest[3] = src[3];
	return;
	memcpy_lte8_5:
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
		dest[3] = src[3];
		dest[4] = src[4];
	return;
	memcpy_lte8_6:
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
		dest[3] = src[3];
		dest[4] = src[4];
		dest[5] = src[5];
	return;
	memcpy_lte8_7:
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
		dest[3] = src[3];
		dest[4] = src[4];
		dest[5] = src[5];
		dest[6] = src[6];
	return;
	memcpy_lte8_8:
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
		dest[3] = src[3];
		dest[4] = src[4];
		dest[5] = src[5];
		dest[6] = src[6];
		dest[7] = src[7];
	return;
}

void  umemset_32(unsigned char *dest,unsigned int val,int size)
{
	for (;size >= 16;size += -16,dest += 16) {
		*(unsigned int*)&dest[0] = val;
		*(unsigned int*)&dest[4] = val;
		*(unsigned int*)&dest[8] = val;
		*(unsigned int*)&dest[12] = val;
	}

	for (;size >= 4;size += -4,dest += 4) {
		*(unsigned int*)dest = val;
	}

	umemset_lte8(dest,val,(int)size);
}

void umemset_64(unsigned char *dest,unsigned long long int val,unsigned int size) //prefer _32()
{
	for (;size >= 16;size += -16,dest += 16) {
		*(unsigned long long int*)&dest[0] = val;
		*(unsigned long long int*)&dest[8] = val;
	}

	for (;size >= 8;size += -8,dest += 8) {
		*(unsigned long long int*)dest = val;
	}

	umemset_lte8(dest,val,(int)size);
}

void umemcpy(void* d,const void* s,int cnt) {
	register unsigned char* pd = d;
	register const unsigned char* ps = s,*pse = ps + cnt;
	
	if ((cnt >= 8) && (! (((ptrdiff_t)pd) & 3) ) && (! (((ptrdiff_t)ps) & 3) ) ) { /*Src & dst aligned*/
		for (;(ps + 8) <= pse; pd += 8,ps += 8) {
			*(unsigned int*)&pd[0] = *(unsigned int*)&ps[0];
			*(unsigned int*)&pd[4] = *(unsigned int*)&ps[4];
		}
	} else if ((cnt >= 8) && (! (((ptrdiff_t)pd) & 3) ) ) {/*Dst aligned*/
		for (;(ps + 8) <= pse; pd += 8,ps += 8) {
			*(unsigned int*)&pd[0] = ((unsigned int)ps[0] << 24) | ((unsigned int)ps[1] << 16) | 
									((unsigned int)ps[2] << 8) | ((unsigned int)ps[3]);
			*(unsigned int*)&pd[4] = ((unsigned int)ps[4] << 24) | ((unsigned int)ps[5] << 16) | 
									((unsigned int)ps[6] << 8) | ((unsigned int)ps[7]);
		}
	} else { /*Don't care*/
		for (;(ps + 8) <= pse; pd += 8,ps += 8) {
			MEMCPY8(pd,ps);
		}
	}

	while (ps < pse) {
		*(pd++) = *(ps++);
	}
}

void umemset(void* d,const unsigned char v,int cnt) {
	register unsigned char* pd = d,*pde = pd + cnt;
	register const unsigned char w = v;

	if (cnt >= 16) {
		if ( (((ptrdiff_t)pd) & 3) ) {
			unsigned char* pdc = (unsigned char*)((ptrdiff_t)pd + (4 - ((ptrdiff_t)pd&3)));
			int a = (ptrdiff_t)pdc - (ptrdiff_t)pd;
			cnt -= a;
			while (a--) {*(pd++) = w; }
			pde = pd + cnt;
		}
	
		register const unsigned int val = u32_mask_table[w];
			for (;pd + 16 <= pde;pd += 16) {
				*(unsigned int*)&pd[0] = val;
				*(unsigned int*)&pd[4] = val;
				*(unsigned int*)&pd[8] = val;
				*(unsigned int*)&pd[12] = val;
			}
			for (;pd + 8 <= pde;pd += 8) {
				*(unsigned int*)&pd[0] = val;
				*(unsigned int*)&pd[4] = val;
			}
			while (pd < pde) {
				*(pd++)=w;
			}
		return;
	}

	while ((pd + 8) <= pde) {
		MEMSET8(pd,w);
		pd += 8;
	}
	
	while (pd < pde) {
		*(pd++)=w;
	}
}



