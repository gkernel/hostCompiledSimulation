/* NIST Secure Hash Algorithm */
/* heavily modified by Uwe Hollerbach uh@alumni.caltech edu */
/* from Peter C. Gutmann's implementation as found in */
/* Applied Cryptography by Bruce Schneier */

/* NIST's proposed modification to SHA of 7/11/94 may be */
/* activated by defining USE_MODIFIED_SHA */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sha.h"
#include "my_mem.h"
//#include "my_defines.h"
//#include "my_variable.h"
/* SHA f()-functions */
extern unsigned int ARR_SIZE;

#define f1(x,y,z)	((x & y) | (~x & z))
#define f2(x,y,z)	(x ^ y ^ z)
#define f3(x,y,z)	((x & y) | (x & z) | (y & z))
#define f4(x,y,z)	(x ^ y ^ z)

/* SHA constants */

#define CONST1		0x5a827999L
#define CONST2		0x6ed9eba1L
#define CONST3		0x8f1bbcdcL
#define CONST4		0xca62c1d6L

/* 32-bit rotate */

#define ROT32(x,n)	((x << n) | (x >> (32 - n)))

#define FUNC(n,i)						\
    temp = ROT32(A,5) + f##n(B,C,D) + E + W[i] + CONST##n;	\
    E = D; D = C; C = ROT32(B,30); B = A; A = temp

/* do SHA transformation */

static void sha_transform(struct SHA_INFO *sha_info)
{
    int i;
    unsigned long temp, A, B, C, D, E, W[80];

    for (i = 0; i < 16; ++i) {
	W[i] = sha_info->data[i];
    }
    for (i = 16; i < 80; ++i) {
	W[i] = W[i-3] ^ W[i-8] ^ W[i-14] ^ W[i-16];
#ifdef USE_MODIFIED_SHA
	W[i] = ROT32(W[i], 1);
#endif /* USE_MODIFIED_SHA */
    }
    A = sha_info->digest[0];
    B = sha_info->digest[1];
    C = sha_info->digest[2];
    D = sha_info->digest[3];
    E = sha_info->digest[4];
#ifdef UNROLL_LOOPS
    FUNC(1, 0);  FUNC(1, 1);  FUNC(1, 2);  FUNC(1, 3);  FUNC(1, 4);
    FUNC(1, 5);  FUNC(1, 6);  FUNC(1, 7);  FUNC(1, 8);  FUNC(1, 9);
    FUNC(1,10);  FUNC(1,11);  FUNC(1,12);  FUNC(1,13);  FUNC(1,14);
    FUNC(1,15);  FUNC(1,16);  FUNC(1,17);  FUNC(1,18);  FUNC(1,19);

    FUNC(2,20);  FUNC(2,21);  FUNC(2,22);  FUNC(2,23);  FUNC(2,24);
    FUNC(2,25);  FUNC(2,26);  FUNC(2,27);  FUNC(2,28);  FUNC(2,29);
    FUNC(2,30);  FUNC(2,31);  FUNC(2,32);  FUNC(2,33);  FUNC(2,34);
    FUNC(2,35);  FUNC(2,36);  FUNC(2,37);  FUNC(2,38);  FUNC(2,39);

    FUNC(3,40);  FUNC(3,41);  FUNC(3,42);  FUNC(3,43);  FUNC(3,44);
    FUNC(3,45);  FUNC(3,46);  FUNC(3,47);  FUNC(3,48);  FUNC(3,49);
    FUNC(3,50);  FUNC(3,51);  FUNC(3,52);  FUNC(3,53);  FUNC(3,54);
    FUNC(3,55);  FUNC(3,56);  FUNC(3,57);  FUNC(3,58);  FUNC(3,59);

    FUNC(4,60);  FUNC(4,61);  FUNC(4,62);  FUNC(4,63);  FUNC(4,64);
    FUNC(4,65);  FUNC(4,66);  FUNC(4,67);  FUNC(4,68);  FUNC(4,69);
    FUNC(4,70);  FUNC(4,71);  FUNC(4,72);  FUNC(4,73);  FUNC(4,74);
    FUNC(4,75);  FUNC(4,76);  FUNC(4,77);  FUNC(4,78);  FUNC(4,79);
#else /* !UNROLL_LOOPS */
    for (i = 0; i < 20; ++i) {
	FUNC(1,i);
    }
    for (i = 20; i < 40; ++i) {
	FUNC(2,i);
    }
    for (i = 40; i < 60; ++i) {
	FUNC(3,i);
    }
    for (i = 60; i < 80; ++i) {
	FUNC(4,i);
    }
#endif /* !UNROLL_LOOPS */
    sha_info->digest[0] += A;
    sha_info->digest[1] += B;
    sha_info->digest[2] += C;
    sha_info->digest[3] += D;
    sha_info->digest[4] += E;
}

#ifdef LITTLE_ENDIAN

/* change endianness of data */

static void byte_reverse(unsigned long *buffer, int count)
{
    int i;
    unsigned char ct[4], *cp;

    count /= sizeof(unsigned long);
    cp = (unsigned char *) buffer;
    for (i = 0; i < count; ++i) {
	ct[0] = cp[0];
	ct[1] = cp[1];
	ct[2] = cp[2];
	ct[3] = cp[3];
	cp[0] = ct[3];
	cp[1] = ct[2];
	cp[2] = ct[1];
	cp[3] = ct[0];
	cp += sizeof(unsigned long);
    }
}

#endif /* LITTLE_ENDIAN */

/* initialize the SHA digest */

void sha_init(struct SHA_INFO *sha_info)
{
    sha_info->digest[0] = 0x67452301L;
    sha_info->digest[1] = 0xefcdab89L;
    sha_info->digest[2] = 0x98badcfeL;
    sha_info->digest[3] = 0x10325476L;
    sha_info->digest[4] = 0xc3d2e1f0L;
    sha_info->count_lo = 0L;
    sha_info->count_hi = 0L;
}

/* update the SHA digest */

void sha_update(struct SHA_INFO *sha_info, unsigned char *buffer, int count)
{
    if ((sha_info->count_lo + ((unsigned long) count << 3)) < sha_info->count_lo) {
	++sha_info->count_hi;
    }
    sha_info->count_lo += (unsigned long) count << 3;
    sha_info->count_hi += (unsigned long) count >> 29;
    while (count >= SHA_BLOCKSIZE) {
	my_memcpy(sha_info->data, buffer, SHA_BLOCKSIZE);
#ifdef LITTLE_ENDIAN
	byte_reverse(sha_info->data, SHA_BLOCKSIZE);
#endif /* LITTLE_ENDIAN */
	sha_transform(sha_info);
	buffer += SHA_BLOCKSIZE;
	count -= SHA_BLOCKSIZE;
    }
    my_memcpy(sha_info->data, buffer, count);
}

/* finish computing the SHA digest */

void sha_final(struct SHA_INFO *sha_info)
{
    int count;
    unsigned long lo_bit_count, hi_bit_count;

    lo_bit_count = sha_info->count_lo;
    hi_bit_count = sha_info->count_hi;
    count = (int) ((lo_bit_count >> 3) & 0x3f);
    ((unsigned char *) sha_info->data)[count++] = 0x80;
    if (count > 56) {
	my_memset((unsigned char *) &sha_info->data + count, 0, 64 - count);
#ifdef LITTLE_ENDIAN
	byte_reverse(sha_info->data, SHA_BLOCKSIZE);
#endif /* LITTLE_ENDIAN */
	sha_transform(sha_info);
	my_memset(&sha_info->data, 0, 56);
    } else {
	my_memset((unsigned char *) &sha_info->data + count, 0, 56 - count);
    }
#ifdef LITTLE_ENDIAN
    byte_reverse(sha_info->data, SHA_BLOCKSIZE);
#endif /* LITTLE_ENDIAN */
    sha_info->data[14] = hi_bit_count;
    sha_info->data[15] = lo_bit_count;
    sha_transform(sha_info);
}

/* compute the SHA digest of a FILE stream */

#define BLOCK_SIZE	8192

void sha_stream(struct SHA_INFO *sha_info, unsigned char *inData, unsigned long dSize)
{
    unsigned long i;
    unsigned long j,k, start,end;
    unsigned long count = 0;

    j = ARR_SIZE/(BLOCK_SIZE); //no. of blocks
    k = ARR_SIZE%(BLOCK_SIZE); //size of last block

    unsigned char data[BLOCK_SIZE];

    sha_init(sha_info);

    //while ((i = fread(data, 1, BLOCK_SIZE, fin)) > 0) {
    for( count = 0; count < j ; count++)
    {
      start = count*(BLOCK_SIZE);
      end = start + (BLOCK_SIZE);

      for(i=start; i<end; i++) //get pcm data from source,
                               //in blocks of DATASIZE
      {
        data[i-start] = inData[i];
      }

      sha_update(sha_info, data, BLOCK_SIZE);
    }

    //check for left over data in source
    if(k)
    {
      start = j*(BLOCK_SIZE);
      end = ARR_SIZE;
      for(i=start; i<end; i++) //get pcm data from source,
                               //in blocks of DATASIZE
      {
        data[i-start] = inData[i];
      }
     
      sha_update(sha_info, data, (end-start));
    }


    sha_final(sha_info);
}

/* print a SHA digest */

void sha_print(struct SHA_INFO *sha_info)
{
    printf("%08lx %08lx %08lx %08lx %08lx\n",
	sha_info->digest[0], sha_info->digest[1], sha_info->digest[2],
	sha_info->digest[3], sha_info->digest[4]);
}
