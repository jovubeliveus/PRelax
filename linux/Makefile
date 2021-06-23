# sample makefile for the C PPTemplate
# j. behrens 3/99

CC = gcc
CCFLAGS = -O3 -DGETRUS -DLINUX -fopenmp
# CCFLAGS = -O3
# CCFLAGS = -g -DDEBUG
SRCSER= ../src_serial/
SRCDAT= ../src_datapar/
LIBS= 
DATLIBS= -lgomp -lm

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

datapar::
	@make copydatapar
	@make maindatapar
	@make clear

# copy source files

copy::
	@cp ${SRCSER}*.c .
	@cp ${SRCSER}*.h .

copydatapar::
	@cp ${SRCDAT}*.c .
	@cp ${SRCDAT}*.h .

# make object files

.c.o:
	${CC} ${CCFLAGS} -c $<

# make target (executable)

main: ${OBJECTS}
	${CC} ${CCFLAGS} -o $@ ${OBJECTS} ${LIBS}

maindatapar: ${OBJECTS}
	${CC} ${CCFLAGS} -o $@ ${OBJECTS} ${LIBS} ${DATLIBS}

clear::
	@rm *.o

tidy::
	@rm -f *.dat *.c *.h core *.m main maindatapar
