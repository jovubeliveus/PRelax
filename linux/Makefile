# sample makefile for the C PPTemplate
# j. behrens 3/99

CC = cc
CCFLAGS = -O3 -DGETRUS -DLINUX
# CCFLAGS = -O3
# CCFLAGS = -g -DDEBUG
SRCSER= ../src_serial/
SRCMPI= ../src_mpi/
LIBS= 
MPILIBS= -lmpi

OBJECTS = \
driver.o \
init.o \
matlab_out.o \
print_result.o \
resid.o \
ticktock.o \
utils.o \
work.o


# default make

all::
	@make copy
	@make main
	@make clear

# copy source files

copy::
	@cp ${SRCSER}*.c .
	@cp ${SRCSER}*.h .

# make object files

.c.o:
	${CC} ${CCFLAGS} -c $<

# make target (executable)

main: ${OBJECTS}
	${CC} ${CCFLAGS} -o $@ ${OBJECTS} ${LIBS}

clear::
	@rm *.o

tidy::
	@rm -f *.dat *.c *.h core *.m main
