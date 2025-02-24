#ifndef SHA_H
#define SHA_H

/* NIST Secure Hash Algorithm */
/* heavily modified from Peter C. Gutmann's implementation */

/* Useful defines & typedefs */

typedef unsigned char BYTE;
typedef unsigned long LONG;

#define SHA_BLOCKSIZE		64
#define SHA_DIGESTSIZE		20

struct SHA_INFO {
    LONG digest[5];		/* message digest */
    LONG count_lo, count_hi;	/* 64-bit bit count */
    LONG data[16];		/* SHA data buffer */
};

void  sha_init (struct SHA_INFO *sha_info, unsigned long sha_info_addr);
void  sha_update (struct SHA_INFO *sha_info, unsigned long sha_info_addr, unsigned char *buffer, unsigned long buffer_addr, int count);
void  sha_final (struct SHA_INFO *sha_info, unsigned long sha_info_addr);

void  sha_stream (struct SHA_INFO *sha_info, unsigned long sha_info_addr, unsigned char *inData, unsigned long inData_addr, unsigned long int dSize);
void  sha_print (struct SHA_INFO *sha_info, unsigned long sha_info_addr);

#endif /* SHA_H */
