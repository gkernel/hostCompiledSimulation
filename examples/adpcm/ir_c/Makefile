#
# Makefile for adpcm and test programs
# -------------------

######################################################################

include ../../Makefile.macros

APP1 = my_ctop_IR

#PHASE = final #when not defined, CC = gcc. otherwise cc = ppc-gcc

TREEDUMP = -fdump-tree-all-blocks-details
OPT = -g -O1 #is O3 in original MiBench download. Use O3 for final testing
DEBUG = -g
#IRDUMP = 1 #defined - dump IR files, undefined - don't.
#PRINT = 1 #if defined and PHASE defined, include soft-float lib. fprintf uses floating point


ifdef PHASE
  CC = $(CROSS_GCC)
  OBJDUMP = $(CROSS_OBJDUMP)
  OEXT = elf
  #ifeq (${IRDUMP},1)
  ifdef IRDUMP
    COPTS = -static ${OPT} ${TREEDUMP} -T generic-hosted.ld
  else
    COPTS = -static ${OPT} -T generic-hosted.ld
  endif
 
  ifdef PRINT
    COPTS += -msoft-float
  endif
else
  CC = $(GCC)
  OBJDUMP = $(HOST_OBJDUMP)
  OEXT = out
  #ifeq (${IRDUMP}, 1)
  ifdef IRDUMP
    COPTS = -static ${OPT} 
  else
    COPTS = -static ${OPT}
  endif
endif

FILE1 = ${APP1}.c adpcm_IR.c
OFILE1 = ${APP1}.${OEXT}
OFILE1PRINT = ${APP1}_print.${OEXT}

OBJDIR = .

all: my_ctest objdump_my_ctest

test:
	./$(OFILE1)
	#./$(OFILE1PRINT)

my_ctest: ${FILE1}
	$(CC) $(COPTS) $^ -o ${OFILE1}

objdump_my_ctest: ${OFILE1}
	${OBJDUMP} -D $^ >& ${OBJDIR}/${APP1}.objdump

my_ctest_print: my_ctop_IR.c adpcm.h adpcm_IR.c in_small_pcm_data.h
	$(CC) $(COPTS) -DPRINT_RESULT my_ctop_IR.c adpcm_IR.c -o $(OFILE1PRINT)

objdump_my_ctest_print: ${OFILE1PRINT}
	${OBJDUMP} -D $^ >& ${OBJDIR}/${APP1}_print.objdump

my_ctest_print_debug: my_ctop_IR.c adpcm.h adpcm_IR.c in_small_pcm_data.h
	$(CC) -static -g  -DPRINT_RESULT my_ctop_IR.c adpcm_IR.c -o $@

clean:
	-rm -rf *.${OEXT} ${OBJDIR}/*.objdump *.c.* my_ctest_print my_ctest_print_debug adpcm_encoding.output
