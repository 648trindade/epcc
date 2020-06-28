#------------------------------------------------#
#                                                #
# Makefile for mixed mode Benchmark code.        #
#                                                #
# Set the CC and CFLAGS for you platform and     #
# then type 'make'.                              #
#------------------------------------------------#

CC=
CFLAGS=

#--------------------------------------#
# Build rules                          #
#--------------------------------------#

EXE=	mixedModeBenchmark

SRC=	src/parallelEnvironment.c \
	src/benchmarkSetup.c \
	src/output.c \
	src/pt_to_pt_pingpong.c \
	src/pt_to_pt_pingping.c \
	src/pt_to_pt_multiPingpong.c \
	src/pt_to_pt_multiPingping.c \
	src/pt_to_pt_haloexchange.c \
	src/collective_barrier.c \
	src/collective_broadcast.c \
	src/collective_scatterGather.c \
	src/collective_reduction.c \
	src/collective_alltoall.c \
	src/mixedModeBenchmarkDriver.c

INC=	src/parallelEnvironment.h \
	src/benchmarkSetup.h \
	src/output.h \
	src/pt_to_pt_pingpong.h \
	src/pt_to_pt_pingping.h \
	src/pt_to_pt_multiPingpong.h \
	src/pt_to_pt_multiPingping.h \
	src/pt_to_pt_haloexchange.h \
	src/collective_barrier.h \
	src/collective_broadcast.h \
	src/collective_scatterGather.h \
	src/collective_reduction.h \
	src/collective_alltoall.h

#
# No need to edit below this line
#

.SUFFIXES:
.SUFFIXES: .c .o

OBJ=	$(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $<


all:	$(EXE)

$(EXE):	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $(notdir $(OBJ)) $(LFLAGS)

$(OBJ):	$(INC) $(MF)

clean:
	rm -f $(OBJ) $(EXE) core 
