/***********************************************************
 Intermediate representation of
    sha/app_dir/sha.c

 Converted by ir2c v0.1

 ***********************************************************/
#include <limits.h>
#include <stdint.h>
#include "ir2c.h"
#include "cacheSim.h"
#include "branchPred.h"
#include "power_estimator.h"
extern unsigned long SP;
extern unsigned long long memAccessCycles;
extern unsigned long long pipelineCycles;
extern struct csim_result_t csim_result;

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
unsigned long ARR_SIZE_addr = 0x55e28;

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


static void  sha_transform (struct SHA_INFO *sha_info, unsigned long sha_info_addr) {
  long unsigned int A_133;
  long unsigned int E_132;
  uintptr_t D_131;
  long unsigned int B_130;
  long unsigned int A_129;
  long unsigned int E_128;
  uintptr_t D_127;
  long unsigned int B_126;
  long unsigned int A_125;
  long unsigned int E_124;
  long unsigned int E_123;
  uintptr_t D_122;
  uintptr_t D_121;
  long unsigned int B_120;
  long unsigned int B_119;
  long unsigned int A_118;
  long unsigned int A_117;
  uintptr_t ivtmp_116;
  uintptr_t ivtmp_115;
  long unsigned int C_114;
  long unsigned int temp_113;
  long unsigned int C_105;
  long unsigned int temp_104;
  long unsigned int C_101;
  long unsigned int temp_100;
  long unsigned int C_97;
  uintptr_t ivtmp_94;
  uintptr_t ivtmp_93;
  uintptr_t D_2940;
  uintptr_t ivtmp_79;
  uintptr_t ivtmp_71;
  uintptr_t D_2917;
  uintptr_t ivtmp_63;
  long unsigned int W[80];
  unsigned long W_addr = 0x10;
  long unsigned int E;
  long unsigned int D;
  long unsigned int C;
  long unsigned int B;
  long unsigned int A;
  long unsigned int temp;

sha_transformbb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
SP = SP + 0x170;
// Simulating I Cache for obj block 0
memAccessCycles += simICache(0x230, 20, &csim_result);
estimate_power("sha_transformbb_2", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 19 - (enterBlock(0xa4, 0xa8) ? 5 : 0);
  ivtmp_94 = (uintptr_t)sha_info;
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  ivtmp_93 = 0;
//  # SUCC: 3 [100.0%]  (fallthru,exec)

sha_transformbb_3:
//  # PRED: 3 [94.1%]  (true,exec) 2 [100.0%]  (fallthru,exec)
memAccessCycles += simDCache((SP + W_addr + (+ivtmp_93)), 0, &csim_result);
// Simulating I Cache for obj block 1
memAccessCycles += simICache(0x244, 28, &csim_result);
estimate_power("sha_transformbb_3", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load GlobalVar sha_info at line 170
pipelineCycles += 12 - (enterBlock(0xa9, 0xaf) ? 5 : 0);
  *(long unsigned int*)((uintptr_t)&W + (uintptr_t)ivtmp_93) = *(long unsigned int*)((uintptr_t)ivtmp_94 + 28);
  ivtmp_93 = ivtmp_93 + 4;
  ivtmp_94 = ivtmp_94 + 4;
  if (ivtmp_93 != 64)
    goto sha_transformbb_3;
  else
    goto sha_transformbb_4;
//  # SUCC: 3 [94.1%]  (true,exec) 4 [5.9%]  (false,exec)

sha_transformbb_4:
//  # PRED: 3 [5.9%]  (false,exec)
// Simulating I Cache for obj block 2
memAccessCycles += simICache(0x260, 8, &csim_result);
estimate_power("sha_transformbb_4", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 9 - (enterBlock(0xb0, 0xb1) ? 5 : 0);
  ivtmp_79 = (uintptr_t)&W[13];
  ivtmp_63 = (uintptr_t)&W;
  D_2940 = ivtmp_63 + 308;
//  # SUCC: 5 [100.0%]  (fallthru,exec)

sha_transformbb_5:
//  # PRED: 5 [98.5%]  (true,exec) 4 [100.0%]  (fallthru,exec)
// Simulating I Cache for obj block 3
memAccessCycles += simICache(0x268, 44, &csim_result);
estimate_power("sha_transformbb_5", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load LocalVar W at line 178
// TODO: UnmappedLS: Load LocalVar W at line 179
// TODO: UnmappedLS: Load LocalVar W at line 181
// TODO: UnmappedLS: Load LocalVar W at line 183
// TODO: UnmappedLS: Store LocalVar W at line 185
pipelineCycles += 23 - (enterBlock(0xb2, 0xbc) ? 5 : 0);
  *(long unsigned int*)((uintptr_t)ivtmp_79 + 12) =  ((*(long unsigned int*)((uintptr_t)ivtmp_79 + (int)4294967276) ^ *(long unsigned int*)((uintptr_t)ivtmp_79)) ^ *(long unsigned int*)((uintptr_t)ivtmp_79 + (int)4294967252)) ^ *(long unsigned int*)((uintptr_t)ivtmp_79 + (int)4294967244);
  ivtmp_79 = ivtmp_79 + 4;
  if (ivtmp_79 != D_2940)
    goto sha_transformbb_5;
  else
    goto sha_transformbb_6;
//  # SUCC: 5 [98.5%]  (true,exec) 6 [1.5%]  (false,exec)

sha_transformbb_6:
//  # PRED: 5 [1.5%]  (false,exec)
memAccessCycles += simDCache((SP + 0xc), 1, &csim_result);  // Spilling Register
memAccessCycles += simDCache((SP + 0x8), 1, &csim_result);  // Spilling Register
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Spilling Register
memAccessCycles += simDCache((SP + 0x0), 1, &csim_result);  // Spilling Register
memAccessCycles += simDCache((SP + 0xc), 1, &csim_result);  // Reading Spilt Register
memAccessCycles += simDCache((SP + 0x8), 1, &csim_result);  // Reading Spilt Register
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Reading Spilt Register
memAccessCycles += simICache(0x460, 1, &csim_result);  // PC Relative Load
// Simulating I Cache for obj block 4
memAccessCycles += simICache(0x294, 68, &csim_result);
estimate_power("sha_transformbb_6", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load GlobalVar sha_info at line 189
// TODO: UnmappedLS: Load GlobalVar sha_info at line 190
// TODO: UnmappedLS: Load GlobalVar sha_info at line 192
// TODO: UnmappedLS: Load GlobalVar sha_info at line 194
// TODO: UnmappedLS: Load GlobalVar sha_info at line 196
pipelineCycles += 24 - (enterBlock(0xbd, 0xcd) ? 5 : 0);
  A = sha_info->digest[0];
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  B = sha_info->digest[1];
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  C = sha_info->digest[2];
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  D = sha_info->digest[3];
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  E = sha_info->digest[4];
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  A_133 = A;
  ivtmp_71 = 0;
//  # SUCC: 7 [100.0%]  (fallthru,exec)

sha_transformbb_7:
//  # PRED: 13 [100.0%]  (fallthru) 6 [100.0%]  (fallthru,exec)
// Simulating I Cache for obj block 5
memAccessCycles += simICache(0x2d8, 48, &csim_result);
estimate_power("sha_transformbb_7", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load LocalVar W at line 206
pipelineCycles += 16 - (enterBlock(0xce, 0xd9) ? 5 : 0);
  temp = (((*(long unsigned int*)((uintptr_t)&W + (uintptr_t)ivtmp_71) + 1518500249) + E) + ((A_133<<27)|(A_133>>(sizeof(A_133)*CHAR_BIT-27)))) + (~B & D | C & B);
  C_97 = (B<<2)|(B>>(sizeof(B)*CHAR_BIT-2));
  ivtmp_71 = ivtmp_71 + 4;
  if (ivtmp_71 != 80)
    goto sha_transformbb_13;
  else
    goto sha_transformbb_8;
//  # SUCC: 13 [95.2%]  (true,exec) 8 [4.8%]  (false,exec)

sha_transformbb_13:
//  # PRED: 7 [95.2%]  (true,exec)
// Simulating I Cache for obj block 6
memAccessCycles += simICache(0x308, 24, &csim_result);
estimate_power("sha_transformbb_13", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 12 - (enterBlock(0xda, 0xdf) ? 5 : 0);
  E = D;
  D = C;
  C = C_97;
  B = A_133;
  A_133 = temp;
  goto sha_transformbb_7;
//  # SUCC: 7 [100.0%]  (fallthru)

sha_transformbb_8:
//  # PRED: 7 [4.8%]  (false,exec)
memAccessCycles += simICache(0x464, 1, &csim_result);  // PC Relative Load
// Simulating I Cache for obj block 7
memAccessCycles += simICache(0x320, 16, &csim_result);
estimate_power("sha_transformbb_8", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 11 - (enterBlock(0xe0, 0xe3) ? 5 : 0);
  D_2917 = ivtmp_63 + 80;
  ivtmp_116 = ivtmp_63;
  E_132 = D;
  D_131 = C;
  B_130 = A_133;
  A_129 = temp;
//  # SUCC: 9 [100.0%]  (fallthru,exec)

sha_transformbb_9:
//  # PRED: 14 [100.0%]  (fallthru) 8 [100.0%]  (fallthru,exec)
// Simulating I Cache for obj block 8
memAccessCycles += simICache(0x330, 44, &csim_result);
estimate_power("sha_transformbb_9", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load LocalVar W at line 228
pipelineCycles += 17 - (enterBlock(0xe4, 0xee) ? 5 : 0);
  temp_100 = (((*(long unsigned int*)((uintptr_t)ivtmp_116 + 80) + 1859775393) + E_132) + ((A_129<<27)|(A_129>>(sizeof(A_129)*CHAR_BIT-27)))) + ((C_97 ^ B_130) ^ D_131);
  C_101 = (B_130<<2)|(B_130>>(sizeof(B_130)*CHAR_BIT-2));
  ivtmp_116 = ivtmp_116 + 4;
  if (ivtmp_116 != D_2917)
    goto sha_transformbb_14;
  else
    goto sha_transformbb_16;
//  # SUCC: 14 [95.2%]  (true,exec) 16 [4.8%]  (false,exec)

sha_transformbb_16:
//  # PRED: 9 [4.8%]  (false,exec)
memAccessCycles += simICache(0x468, 1, &csim_result);  // PC Relative Load
// Simulating I Cache for obj block 10
memAccessCycles += simICache(0x374, 16, &csim_result);
estimate_power("sha_transformbb_16", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 11 - (enterBlock(0xf5, 0xf8) ? 5 : 0);
  ivtmp_115 = ivtmp_63;
  E_128 = D_131;
  D_127 = C_97;
  B_126 = A_129;
  A_125 = temp_100;
  goto sha_transformbb_10;
//  # SUCC: 10 [100.0%]  (fallthru)

sha_transformbb_14:
//  # PRED: 9 [95.2%]  (true,exec)
// Simulating I Cache for obj block 9
memAccessCycles += simICache(0x35c, 24, &csim_result);
estimate_power("sha_transformbb_14", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 12 - (enterBlock(0xef, 0xf4) ? 5 : 0);
  E_132 = D_131;
  D_131 = C_97;
  C_97 = C_101;
  B_130 = A_129;
  A_129 = temp_100;
  goto sha_transformbb_9;
//  # SUCC: 9 [100.0%]  (fallthru)

sha_transformbb_15:
//  # PRED: 10 [95.2%]  (true,exec)
// Simulating I Cache for obj block 12
memAccessCycles += simICache(0x3b8, 24, &csim_result);
estimate_power("sha_transformbb_15", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 12 - (enterBlock(0x106, 0x10b) ? 5 : 0);
  E_128 = D_127;
  D_127 = C_101;
  C_101 = C_105;
  B_126 = A_125;
  A_125 = temp_104;
//  # SUCC: 10 [100.0%]  (fallthru)

sha_transformbb_10:
//  # PRED: 15 [100.0%]  (fallthru) 16 [100.0%]  (fallthru)
// Simulating I Cache for obj block 11
memAccessCycles += simICache(0x384, 52, &csim_result);
estimate_power("sha_transformbb_10", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load LocalVar W at line 249
pipelineCycles += 18 - (enterBlock(0xf9, 0x105) ? 5 : 0);
  temp_104 = (((*(long unsigned int*)((uintptr_t)ivtmp_115 + 160) + (int)2400959708) + E_128) + ((A_125<<27)|(A_125>>(sizeof(A_125)*CHAR_BIT-27)))) + ((D_127 | C_101) & B_126 | D_127 & C_101);
  C_105 = (B_126<<2)|(B_126>>(sizeof(B_126)*CHAR_BIT-2));
  ivtmp_115 = ivtmp_115 + 4;
  if (ivtmp_115 != D_2917)
    goto sha_transformbb_15;
  else
    goto sha_transformbb_18;
//  # SUCC: 15 [95.2%]  (true,exec) 18 [4.8%]  (false,exec)

sha_transformbb_18:
//  # PRED: 10 [4.8%]  (false,exec)
memAccessCycles += simICache(0x46c, 1, &csim_result);  // PC Relative Load
// Simulating I Cache for obj block 13
memAccessCycles += simICache(0x3d0, 8, &csim_result);
estimate_power("sha_transformbb_18", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 9 - (enterBlock(0x10c, 0x10d) ? 5 : 0);
  E_123 = D_127;
  D_121 = C_101;
  B_119 = A_125;
  A_117 = temp_104;
//  # SUCC: 11 [100.0%]  (fallthru)

sha_transformbb_11:
//  # PRED: 17 [100.0%]  (fallthru) 18 [100.0%]  (fallthru)
// Simulating I Cache for obj block 14
memAccessCycles += simICache(0x3d8, 44, &csim_result);
estimate_power("sha_transformbb_11", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load LocalVar W at line 270
pipelineCycles += 17 - (enterBlock(0x10e, 0x118) ? 5 : 0);
  temp_113 = (((*(long unsigned int*)((uintptr_t)ivtmp_63 + 240) + (int)3395469782) + E_123) + ((A_117<<27)|(A_117>>(sizeof(A_117)*CHAR_BIT-27)))) + ((C_105 ^ B_119) ^ D_121);
  C_114 = (B_119<<2)|(B_119>>(sizeof(B_119)*CHAR_BIT-2));
  ivtmp_63 = ivtmp_63 + 4;
  if (ivtmp_63 != D_2917)
    goto sha_transformbb_17;
  else
    goto sha_transformbb_19;
//  # SUCC: 17 [95.2%]  (true,exec) 19 [4.8%]  (false,exec)

sha_transformbb_17:
//  # PRED: 11 [95.2%]  (true,exec)
// Simulating I Cache for obj block 15
memAccessCycles += simICache(0x404, 24, &csim_result);
estimate_power("sha_transformbb_17", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 12 - (enterBlock(0x119, 0x11e) ? 5 : 0);
  E_123 = D_121;
  D_121 = C_105;
  C_105 = C_114;
  B_119 = A_117;
  A_117 = temp_113;
  goto sha_transformbb_11;
//  # SUCC: 11 [100.0%]  (fallthru)

sha_transformbb_19:
//  # PRED: 11 [4.8%]  (false,exec)
memAccessCycles += simDCache((SP + 0xc), 1, &csim_result);  // Reading Spilt Register
memAccessCycles += simDCache((SP + 0x8), 1, &csim_result);  // Reading Spilt Register
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Reading Spilt Register
memAccessCycles += simDCache((SP + 0x0), 1, &csim_result);  // Reading Spilt Register
pipelineCycles += 34 - (enterBlock(0x11f, 0x12f) ? 5 : 0);
  E_124 = D_121;
  D_122 = C_105;
  B_120 = A_117;
  A_118 = temp_113;
//  # SUCC: 12 [100.0%]  (fallthru)

sha_transformbb_12:
//  # PRED: 19 [100.0%]  (fallthru)
// Simulating I Cache for obj block 16
memAccessCycles += simICache(0x41c, 68, &csim_result);
estimate_power("sha_transformbb_12", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Store GlobalVar sha_info at line 288
// TODO: UnmappedLS: Store GlobalVar sha_info at line 291
// TODO: UnmappedLS: Store GlobalVar sha_info at line 294
// TODO: UnmappedLS: Store GlobalVar sha_info at line 297
// TODO: UnmappedLS: Store GlobalVar sha_info at line 300
  sha_info->digest[0] =  A_118 + A;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[1] =  B_120 + sha_info->digest[1];
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[2] =  C_114 + sha_info->digest[2];
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[3] =  D_122 + sha_info->digest[3];
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[4] =  E_124 + sha_info->digest[4];
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  return;
//  # SUCC: EXIT [100.0%] 

}



void  sha_init (struct SHA_INFO *sha_info, unsigned long sha_info_addr) {
sha_initbb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
SP = SP + 0x0;
memAccessCycles += simICache(0x4b4, 1, &csim_result);  // PC Relative Load
memAccessCycles += simICache(0x4b8, 1, &csim_result);  // PC Relative Load
memAccessCycles += simICache(0x4bc, 1, &csim_result);  // PC Relative Load
memAccessCycles += simICache(0x4c0, 1, &csim_result);  // PC Relative Load
// Simulating I Cache for obj block 0
memAccessCycles += simICache(0x470, 68, &csim_result);
estimate_power("sha_initbb_2", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Store GlobalVar sha_info at line 311
// TODO: UnmappedLS: Store GlobalVar sha_info at line 316
// TODO: UnmappedLS: Store GlobalVar sha_info at line 318
// TODO: UnmappedLS: Store GlobalVar sha_info at line 320
// TODO: UnmappedLS: Store GlobalVar sha_info at line 322
// TODO: UnmappedLS: Store GlobalVar sha_info at line 324
// TODO: UnmappedLS: Store GlobalVar sha_info at line 325
pipelineCycles += 23 - (enterBlock(0x136, 0x146) ? 5 : 0);
  sha_info->digest[0] = 1732584193;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[1] = 4023233417;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[2] = 2562383102;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[3] = 271733878;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->digest[4] = 3285377520;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->count_lo = 0;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->count_hi = 0;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  return;
//  # SUCC: EXIT [100.0%] 

}



void  sha_print (struct SHA_INFO *sha_info, unsigned long sha_info_addr) {
sha_printbb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
SP = SP + 0x10;
// Simulating I Cache for obj block 0
memAccessCycles += simICache(0x718, 44, &csim_result);
estimate_power("sha_printbb_2", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 16 - (enterBlock(0x1e8, 0x1f2) ? 5 : 0);
  printf (&"%08lx %08lx %08lx %08lx %08lx\n"[0], sha_info->digest[0], sha_info->digest[1], sha_info->digest[2], sha_info->digest[3], sha_info->digest[4]);
  return;
//  # SUCC: EXIT [100.0%] 

}



void  sha_final (struct SHA_INFO *sha_info, unsigned long sha_info_addr) {
  int count_203;
  long unsigned int hi_bit_count;
  long unsigned int lo_bit_count;
  int count;
  long unsigned int * D_2805;

sha_finalbb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
SP = SP + 0x18;
// Simulating I Cache for obj block 0
memAccessCycles += simICache(0x58c, 60, &csim_result);
estimate_power("sha_finalbb_2", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Store GlobalVar sha_info at line 393
pipelineCycles += 23 - (enterBlock(0x181, 0x18f) ? 5 : 0);
  lo_bit_count = sha_info->count_lo;
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  hi_bit_count = sha_info->count_hi;
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  count = (int) (lo_bit_count >> 3) & 63;
  D_2805 = &sha_info->data;
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  *(unsigned char*)( (uintptr_t)D_2805 + (unsigned int) count) = 128;
  count_203 = count + 1;
  if (count_203 > 56)
    goto sha_finalbb_3;
  else
    goto sha_finalbb_4;
//  # SUCC: 3 [39.0%]  (true,exec) 4 [61.0%]  (false,exec)

sha_finalbb_3:
//  # PRED: 2 [39.0%]  (true,exec)
// Simulating I Cache for obj block 2
memAccessCycles += simICache(0x5ec, 8, &csim_result);
estimate_power("sha_finalbb_3", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 8 - (enterBlock(0x199, 0x19a) ? 5 : 0);
  my_memset (D_2805 + (unsigned int) count_203, D_2805_addr,  0,  (size_t) (64 - count_203));
  sha_transform (sha_info, sha_info_addr);
  my_memset (D_2805, D_2805_addr,  0,  56);
  goto sha_finalbb_5;
//  # SUCC: 5 [100.0%]  (fallthru,exec)

sha_finalbb_4:
//  # PRED: 2 [61.0%]  (false,exec)
// Simulating I Cache for obj block 1
memAccessCycles += simICache(0x5c8, 36, &csim_result);
estimate_power("sha_finalbb_4", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 12 - (enterBlock(0x190, 0x198) ? 5 : 0);
  my_memset (D_2805 + (unsigned int) count_203, D_2805_addr,  0,  (size_t) (56 - count_203));
//  # SUCC: 5 [100.0%]  (fallthru,exec)

sha_finalbb_5:
//  # PRED: 3 [100.0%]  (fallthru,exec) 4 [100.0%]  (fallthru,exec)
// Simulating I Cache for obj block 3
memAccessCycles += simICache(0x5f4, 24, &csim_result);
estimate_power("sha_finalbb_5", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Store GlobalVar sha_info at line 411
// TODO: UnmappedLS: Store GlobalVar sha_info at line 412
pipelineCycles += 16 - (enterBlock(0x19b, 0x1a0) ? 5 : 0);
  sha_info->data[14] = hi_bit_count;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->data[15] = lo_bit_count;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_transform (sha_info, sha_info_addr);
  return;
//  # SUCC: EXIT [100.0%] 

}



void  sha_update (struct SHA_INFO *sha_info, unsigned long sha_info_addr, unsigned char *buffer, unsigned long buffer_addr, int count) {
  uintptr_t D_3103;
  uintptr_t ivtmp_232;
  int D_3089;
  uintptr_t D_3086;
  long unsigned int * D_2795;
  long unsigned int D_2787;
  long unsigned int count_1;
  long unsigned int D_2785;

sha_updatebb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
SP = SP + 0x30;
pipelineCycles += 32 - (enterBlock(0x14d, 0x160) ? 5 : 0);
  D_2785 = sha_info->count_lo;
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  count_1 = (long unsigned int) count;
  D_2787 = count_1 << 3;
  if (D_2785 > D_2787 + D_2785)
    goto sha_updatebb_3;
  else
    goto sha_updatebb_4;
//  # SUCC: 3 [50.0%]  (true,exec) 4 [50.0%]  (false,exec)

sha_updatebb_3:
//  # PRED: 2 [50.0%]  (true,exec)
  sha_info->count_hi =  sha_info->count_hi + 1;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
//  # SUCC: 4 [100.0%]  (fallthru,exec)

sha_updatebb_4:
//  # PRED: 2 [50.0%]  (false,exec) 3 [100.0%]  (fallthru,exec)
// Simulating I Cache for obj block 0
memAccessCycles += simICache(0x4c4, 80, &csim_result);
estimate_power("sha_updatebb_4", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load GlobalVar sha_info at line 338
// TODO: UnmappedLS: Load GlobalVar sha_info at line 342
// TODO: UnmappedLS: Store GlobalVar sha_info at line 344
// TODO: UnmappedLS: Load GlobalVar sha_info at line 345
// TODO: UnmappedLS: Store GlobalVar sha_info at line 347
// TODO: UnmappedLS: Load GlobalVar sha_info at line 348
// TODO: UnmappedLS: Store GlobalVar sha_info at line 350
  sha_info->count_lo =  D_2787 + sha_info->count_lo;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  sha_info->count_hi =  (count_1 >> 29) + sha_info->count_hi;
  memAccessCycles += simDCache(sha_info_addr, 0, &csim_result);
  if (count > 63)
    goto sha_updatebb_5;
  else
    goto sha_updatebb_8;
//  # SUCC: 5 [91.0%]  (true,exec) 8 [9.0%]  (false,exec)

sha_updatebb_5:
//  # PRED: 4 [91.0%]  (true,exec)
// Simulating I Cache for obj block 1
memAccessCycles += simICache(0x514, 16, &csim_result);
estimate_power("sha_updatebb_5", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 11 - (enterBlock(0x161, 0x164) ? 5 : 0);
  D_2795 = &sha_info->data;
  memAccessCycles += simDCache(sha_info_addr, 1, &csim_result);
  ivtmp_232 = 0;
//  # SUCC: 6 [100.0%]  (fallthru,exec)

sha_updatebb_6:
//  # PRED: 6 [91.0%]  (true,exec) 5 [100.0%]  (fallthru,exec)
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Spilling Register
// Simulating I Cache for obj block 2
memAccessCycles += simICache(0x524, 44, &csim_result);
estimate_power("sha_updatebb_6", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 15 - (enterBlock(0x165, 0x16f) ? 5 : 0);
  D_3103 = ivtmp_232 + (uintptr_t)buffer;
  memAccessCycles += simDCache(buffer_addr, 1, &csim_result);
  my_memcpy (D_2795, D_2795_addr,   D_3103, D_3103_addr,  64);
  sha_transform (sha_info, sha_info_addr);
  ivtmp_232 = ivtmp_232 + 64;
  if ((int) (count_1 - ivtmp_232) > 63)
    goto sha_updatebb_6;
  else
    goto sha_updatebb_7;
//  # SUCC: 6 [91.0%]  (true,exec) 7 [9.0%]  (false,exec)

sha_updatebb_7:
//  # PRED: 6 [9.0%]  (false,exec)
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Reading Spilt Register
// Simulating I Cache for obj block 3
memAccessCycles += simICache(0x550, 32, &csim_result);
estimate_power("sha_updatebb_7", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 15 - (enterBlock(0x170, 0x177) ? 5 : 0);
  D_3086 = (count_1 + (int)4294967232) / 64;
  buffer = (uintptr_t)buffer + (D_3086 + 1) * 64;
  memAccessCycles += simDCache(buffer_addr, 0, &csim_result);
  D_3089 = count + -64;
  count = D_3089 + (int) D_3086 * -64;
//  # SUCC: 8 [100.0%]  (fallthru,exec)

sha_updatebb_8:
//  # PRED: 7 [100.0%]  (fallthru,exec) 4 [9.0%]  (false,exec)
// Simulating I Cache for obj block 4
memAccessCycles += simICache(0x570, 28, &csim_result);
estimate_power("sha_updatebb_8", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 20 - (enterBlock(0x178, 0x17e) ? 5 : 0);
  my_memcpy (&sha_info->data, sha_info_addr,  buffer, buffer_addr,  (size_t) count);
  return;
//  # SUCC: EXIT [100.0%] 

}



void  sha_stream (struct SHA_INFO *sha_info, unsigned long sha_info_addr, unsigned char *inData, unsigned long inData_addr, unsigned long int dSize) {
  long unsigned int end_289;
  long unsigned int end_288;
  uintptr_t ivtmp_273;
  uintptr_t D_3143;
  uintptr_t ivtmp_267;
  unsigned char data[8192];
  long unsigned int count;
  long unsigned int end;
  long unsigned int start;
  long unsigned int j;
  unsigned int ARR_SIZE_4;

sha_streambb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
SP = SP + 0x2030;
memAccessCycles += simICache(0x714, 1, &csim_result);  // PC Relative Load
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Spilling Register
memAccessCycles += simDCache(ARR_SIZE_addr, 1, &csim_result);
// Simulating I Cache for obj block 0
memAccessCycles += simICache(0x60c, 48, &csim_result);
estimate_power("sha_streambb_2", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 23 - (enterBlock(0x1a3, 0x1ae) ? 5 : 0);
  ARR_SIZE_4 = ARR_SIZE;
  j = ARR_SIZE_4 / 8192;
  sha_init (sha_info, sha_info_addr);
  if (j != 0)
    goto sha_streambb_13;
  else
    goto sha_streambb_6;
//  # SUCC: 13 [91.0%]  (true,exec) 6 [9.0%]  (false,exec)

sha_streambb_13:
//  # PRED: 2 [91.0%]  (true,exec)
// Simulating I Cache for obj block 1
memAccessCycles += simICache(0x63c, 36, &csim_result);
estimate_power("sha_streambb_13", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 19 - (enterBlock(0x1af, 0x1b7) ? 5 : 0);
  end_289 = 0;
  count = 0;
//  # SUCC: 3 [100.0%]  (fallthru)

sha_streambb_3:
//  # PRED: 12 [100.0%]  (fallthru) 13 [100.0%]  (fallthru)
pipelineCycles += 9 - (enterBlock(0x1b8, 0x1ba) ? 5 : 0);
  end_288 = end_289 + 8192;
  if (end_288 > end_289)
    goto sha_streambb_14;
  else
    goto sha_streambb_5;
//  # SUCC: 14 [99.0%]  (true,exec) 5 [1.0%]  (false,exec)

sha_streambb_14:
//  # PRED: 3 [99.0%]  (true,exec)
// Simulating I Cache for obj block 3
memAccessCycles += simICache(0x66c, 4, &csim_result);
estimate_power("sha_streambb_14", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 8 - (enterBlock(0x1bb, 0x1bb) ? 5 : 0);
  ivtmp_273 = 0;
//  # SUCC: 4 [100.0%]  (fallthru)

sha_streambb_4:
//  # PRED: 4 [99.0%]  (true,exec) 14 [100.0%]  (fallthru)
// Simulating I Cache for obj block 4
memAccessCycles += simICache(0x670, 24, &csim_result);
estimate_power("sha_streambb_4", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load GlobalVar in_Data at line 445
// TODO: UnmappedLS: Inaccurately Matched Store at line 446
pipelineCycles += 11 - (enterBlock(0x1bc, 0x1c1) ? 5 : 0);
  *(unsigned char*)((uintptr_t)&data + (uintptr_t)ivtmp_273) = *(unsigned char *)((unsigned char *) (end_289 + (uintptr_t)inData) + (uintptr_t)ivtmp_273);
  ivtmp_273 = ivtmp_273 + 1;
  if (ivtmp_273 != 8192)
    goto sha_streambb_4;
  else
    goto sha_streambb_5;
//  # SUCC: 4 [99.0%]  (true,exec) 5 [1.0%]  (false,exec)

sha_streambb_5:
//  # PRED: 4 [1.0%]  (false,exec) 3 [1.0%]  (false,exec)
// Simulating I Cache for obj block 5
memAccessCycles += simICache(0x688, 32, &csim_result);
estimate_power("sha_streambb_5", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 13 - (enterBlock(0x1c2, 0x1c9) ? 5 : 0);
  sha_update (sha_info, sha_info_addr,  &data, data_addr,  8192);
  count = count + 1;
  if (j > count)
    goto sha_streambb_12;
  else
    goto sha_streambb_6;
//  # SUCC: 12 [91.0%]  (true,exec) 6 [9.0%]  (false,exec)

sha_streambb_12:
//  # PRED: 5 [91.0%]  (true,exec)
// Simulating I Cache for obj block 2
memAccessCycles += simICache(0x660, 12, &csim_result);
estimate_power("sha_streambb_12", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
  end_289 = end_288;
  goto sha_streambb_3;
//  # SUCC: 3 [100.0%]  (fallthru)

sha_streambb_6:
//  # PRED: 5 [9.0%]  (false,exec) 2 [9.0%]  (false,exec)
memAccessCycles += simDCache((SP + 0x4), 1, &csim_result);  // Reading Spilt Register
// Simulating I Cache for obj block 6
memAccessCycles += simICache(0x6a8, 12, &csim_result);
estimate_power("sha_streambb_6", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 9 - (enterBlock(0x1ca, 0x1cc) ? 5 : 0);
  if (ARR_SIZE_4 & 8191 != 0)
    goto sha_streambb_7;
  else
    goto sha_streambb_11;
//  # SUCC: 7 [61.0%]  (true,exec) 11 [39.0%]  (false,exec)

sha_streambb_7:
//  # PRED: 6 [61.0%]  (true,exec)
memAccessCycles += simICache(0x714, 1, &csim_result);  // PC Relative Load
// Simulating I Cache for obj block 7
memAccessCycles += simICache(0x6b4, 20, &csim_result);
estimate_power("sha_streambb_7", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 12 - (enterBlock(0x1cd, 0x1d1) ? 5 : 0);
  start = j * 8192;
  memAccessCycles += simDCache(ARR_SIZE_addr, 1, &csim_result);
  end = ARR_SIZE;
  if (start < end)
    goto sha_streambb_8;
  else
    goto sha_streambb_10;
//  # SUCC: 8 [99.0%]  (true,exec) 10 [1.0%]  (false,exec)

sha_streambb_8:
//  # PRED: 7 [99.0%]  (true,exec)
// Simulating I Cache for obj block 8
memAccessCycles += simICache(0x6c8, 16, &csim_result);
estimate_power("sha_streambb_8", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 11 - (enterBlock(0x1d2, 0x1d5) ? 5 : 0);
  D_3143 = end - start;
  ivtmp_267 = 0;
//  # SUCC: 9 [100.0%]  (fallthru,exec)

sha_streambb_9:
//  # PRED: 9 [99.0%]  (true,exec) 8 [100.0%]  (fallthru,exec)
memAccessCycles += simDCache((SP + 0x8), 1, &csim_result);  // Spilling Register
// Simulating I Cache for obj block 9
memAccessCycles += simICache(0x6d8, 20, &csim_result);
estimate_power("sha_streambb_9", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
// TODO: UnmappedLS: Load GlobalVar in_Data at line 470
pipelineCycles += 11 - (enterBlock(0x1d6, 0x1da) ? 5 : 0);
  *(unsigned char*)((uintptr_t)&data + (uintptr_t)ivtmp_267) = *(unsigned char *)((uintptr_t)inData + start + (uintptr_t)ivtmp_267);
  memAccessCycles += simDCache(inData_addr + (+start+ivtmp_267), 1, &csim_result);
  ivtmp_267 = ivtmp_267 + 1;
  if (ivtmp_267 != D_3143)
    goto sha_streambb_9;
  else
    goto sha_streambb_10;
//  # SUCC: 9 [99.0%]  (true,exec) 10 [1.0%]  (false,exec)

sha_streambb_10:
//  # PRED: 9 [1.0%]  (false,exec) 7 [1.0%]  (false,exec)
// Simulating I Cache for obj block 10
memAccessCycles += simICache(0x6ec, 16, &csim_result);
estimate_power("sha_streambb_10", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 10 - (enterBlock(0x1db, 0x1de) ? 5 : 0);
  sha_update (sha_info, sha_info_addr,  &data, data_addr,  (int) (end - start));
//  # SUCC: 11 [100.0%]  (fallthru,exec)

sha_streambb_11:
//  # PRED: 6 [39.0%]  (false,exec) 10 [100.0%]  (fallthru,exec)
// Simulating I Cache for obj block 11
memAccessCycles += simICache(0x6fc, 24, &csim_result);
estimate_power("sha_streambb_11", pipelineCycles, memAccessCycles, csim_result.L2Hits, (csim_result.prefetches + csim_result.L2Misses));
pipelineCycles += 19 - (enterBlock(0x1df, 0x1e4) ? 5 : 0);
  sha_final (sha_info, sha_info_addr);
  return;
//  # SUCC: EXIT [100.0%] 

}


