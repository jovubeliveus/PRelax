/*****************************************************************

 NAME:
	global.h

 FUNCTION:
	function prototypes for the matrix multiplication
	benchmark

 VERSION(S):
	1. original			j. behrens	6/93
	2. changed for PPtemplate	j. behrens	3/99

*****************************************************************/


/* template declarations */
float **mat_alloc();
void mat_free();
float *vec_alloc();
void vec_free();
void prerror();
void print_result();
float ticktock();
void init();
void work();
float resid();
void matlab_out();

#ifndef GLOBAL_DEFINED
#define GLOBAL_DEFINED

/* global values */
#ifdef MAIN_FILE
float DX;	/* mesh size */
int NLEN;	/* number of gridpoints */
int numprocs;   /* number of processors */
int ITER=1000;	/* number of iterations */
#else
extern float DX;
extern int NLEN;
extern int numprocs;
extern int ITER;
#endif

#endif /* GLOBAL_DEFINED */
