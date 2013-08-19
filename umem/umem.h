#ifndef _umem_
#define _umem_
/*Some mem copy hacks ~conle*/
void blendcpy_lte8(unsigned char *dest,const unsigned char *src, unsigned char b,int cnt);
void umemset_lte8(unsigned char *dest,unsigned char v,int cnt);
void umemcpy_lte8(unsigned char *dest,const unsigned char *src, int cnt);
void umemset_32(unsigned char *dest,unsigned int val,int size);
void umemset_64(unsigned char *dest,unsigned long long int val,unsigned int size);
void umemcpy(void* d,const void* s,int cnt);
void umemset(void* d,const unsigned char v,int cnt);
#endif

