/***********************************************************
 Intermediate representation of
    adpcm/app_dir/my_ctop.c

 Converted by ir2c v0.1

 ***********************************************************/
#include <limits.h>
#include <stdint.h>
#include "ir2c.h"

/*
** Timing - Test timing on adpcm coder and decoder.
**
** The program creates 10Kb garbage, and runs the compressor and
** the decompressor on it.
*/

#include <stdio.h>
#include "adpcm.h"
#include "in_small.h"
//#include "in_large.h"
#include "my_variables.h"
#define DATASIZE 10*1024	/* Data block size */
//ARR_SIZE is the number of short type elements in 
//input data array. defined in in_data_small.h
//unsigned int ARR_SIZE = 13305601;
//unsigned int ARR_SIZE = 684433;
short int pcmdata[DATASIZE];
char adpcmdata[DATASIZE/2];

struct adpcm_state coder_1_state;


int main() {
  long unsigned int end_46;
  int i_45;
  long unsigned int end_44;
  long unsigned int end_43;
  long unsigned int start_40;
  uintptr_t ivtmp_34;
  int D_2229;
  uintptr_t ivtmp_28;
  long unsigned int count;
  long unsigned int end;
  long unsigned int start;
  long unsigned int j;
  int i;
  unsigned int ARR_SIZE_0;

mainbb_2:
//  # PRED: ENTRY [100.0%]  (fallthru,exec)
  ARR_SIZE_0 = ARR_SIZE;
  j = ARR_SIZE_0 / 10240;
  if (j != 0)
    goto mainbb_14;
  else
    goto mainbb_7;
//  # SUCC: 14 [91.0%]  (true,exec) 7 [9.0%]  (false,exec)

mainbb_14:
//  # PRED: 2 [91.0%]  (true,exec)
  end_43 = 0;
  count = 0;
//  # SUCC: 3 [100.0%]  (fallthru)

mainbb_3:
//  # PRED: 13 [100.0%]  (fallthru) 14 [100.0%]  (fallthru)
  end_46 = end_43 + 10240;
  if (end_43 < end_46)
    goto mainbb_4;
  else
    goto mainbb_6;
//  # SUCC: 4 [99.0%]  (true,exec) 6 [1.0%]  (false,exec)

mainbb_4:
//  # PRED: 3 [99.0%]  (true,exec)
  i_45 = (int) end_43;
  ivtmp_34 = (uintptr_t)&in_Data[i_45];
  end_44 = end_43;
//  # SUCC: 5 [100.0%]  (fallthru,exec)

mainbb_5:
//  # PRED: 5 [99.0%]  (true,exec) 4 [100.0%]  (fallthru,exec)
  pcmdata[end_44 - end_43] = *(short int*)((uintptr_t)ivtmp_34);
  i_45 = i_45 + 1;
  end_44 = (long unsigned int) i_45;
  ivtmp_34 = ivtmp_34 + 2;
  if (end_44 < end_46)
    goto mainbb_5;
  else
    goto mainbb_6;
//  # SUCC: 5 [99.0%]  (true,exec) 6 [1.0%]  (false,exec)

mainbb_6:
//  # PRED: 5 [1.0%]  (false,exec) 3 [1.0%]  (false,exec)
  adpcm_coder (&pcmdata, &adpcmdata, 10240, &coder_1_state);
  count = count + 1;
  if (j > count)
    goto mainbb_13;
  else
    goto mainbb_7;
//  # SUCC: 13 [91.0%]  (true,exec) 7 [9.0%]  (false,exec)

mainbb_13:
//  # PRED: 6 [91.0%]  (true,exec)
  end_43 = end_46;
  goto mainbb_3;
//  # SUCC: 3 [100.0%]  (fallthru)

mainbb_7:
//  # PRED: 6 [9.0%]  (false,exec) 2 [9.0%]  (false,exec)
  if (ARR_SIZE_0 % 10240 != 0)
    goto mainbb_8;
  else
    goto mainbb_12;
//  # SUCC: 8 [61.0%]  (true,exec) 12 [39.0%]  (false,exec)

mainbb_8:
//  # PRED: 7 [61.0%]  (true,exec)
  start_40 = j * 10240;
  end = ARR_SIZE;
  if (start_40 < end)
    goto mainbb_9;
  else
    goto mainbb_11;
//  # SUCC: 9 [99.0%]  (true,exec) 11 [1.0%]  (false,exec)

mainbb_9:
//  # PRED: 8 [99.0%]  (true,exec)
  i = (int) start_40;
  ivtmp_28 = (uintptr_t)&in_Data[i];
  D_2229 = (int) end;
  start = start_40;
//  # SUCC: 10 [100.0%]  (fallthru,exec)

mainbb_10:
//  # PRED: 10 [99.0%]  (true,exec) 9 [100.0%]  (fallthru,exec)
  pcmdata[start - start_40] = *(short int*)((uintptr_t)ivtmp_28);
  i = i + 1;
  start = (long unsigned int) i;
  ivtmp_28 = ivtmp_28 + 2;
  if (i != D_2229)
    goto mainbb_10;
  else
    goto mainbb_11;
//  # SUCC: 10 [99.0%]  (true,exec) 11 [1.0%]  (false,exec)

mainbb_11:
//  # PRED: 10 [1.0%]  (false,exec) 8 [1.0%]  (false,exec)
  adpcm_coder (&pcmdata, &adpcmdata, (int) (end - start_40), &coder_1_state);
//  # SUCC: 12 [100.0%]  (fallthru,exec)

mainbb_12:
//  # PRED: 7 [39.0%]  (false,exec) 11 [100.0%]  (fallthru,exec)
  return 0;
//  # SUCC: EXIT [100.0%] 

}


