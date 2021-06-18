/*****************************************************************

 NAME:
	matrix_mult

 FUNCTION:
	main (calling) driver routine for the parallelization tests

 SYNTAX:
	matrix.ibm [int]

 ON INPUT:
	number of lines/collumns of the matrix
	(optional default is 128)

 ON OUTPUT:
	formatted output on stdout with timing results and
	mflops rates

 CALLS:
	ticktock, init, multkji, print_result, matrix, error_out

 COMMENTS:
	we use a red-black gauss-seidel relaxation for testing

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j. behrens	6/93
	2. blocked included		j. behrens	7/93
	3. changed for PPtemplate	j. behrens	3/99

*****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#ifndef MACOSX
#include <malloc.h>
#endif
#define MAIN_FILE
#include "global.h"
#undef MAIN_FILE

void main(argc, argv)
int argc;
char *argv[];
{

/* constants, timing variables, count variables, etc. */
	int NBIG= 1, ir= 0, NSPACE, i, n, DEFAULTLEN= 129;
	float RMEG= 1.e6, OPS, t1, t2, TOVH, RKIL= 1./1000.;
	float result, tmp;
	int numprocs=1;
	long int n2, n6=6, nit, nop;

/* constants for the overhead determination, RTIMLOOP := 1/NTIMLOOP ! */
	int   NTIMLOOP=10;
	float RTIMLOOP=(1./10.);

/* real arrays allocated dynamically later */
	float **u, **f, **r;

/* arrays for the measurements */
	float times[10], flops[10];
	char *crout[10];

/* we assume zero timing overhead */
	TOVH= 0.0;

/* evaluate command line arguments */
	if (argc == 1) 
		n= DEFAULTLEN;
	else if (argc == 2) {
		n= atoi(argv[1]);
	}
	else {
		fprintf(stderr,"USAGE: %s [n], where n is the (odd) number of gridpoints \n", argv[0]);
		prerror(12," incorrect number of command line arguments!");
	}
	NLEN= n;

/* calculate mesh, i want an odd number of gridpoints */
	if(((NLEN/2)*2) == NLEN) {
		NLEN=NLEN-1;
		fprintf(stdout,"INFO: NLEN set to new (odd) value: %8i \n",NLEN);
	}
	DX=1./((float) NLEN-1);
	
	NSPACE= 3* NLEN* NLEN* sizeof(float); /* this depends on the allocation */

/* calculate number of operations this depends on the operation in work() */
	n2=  (long int)(NLEN-2);
	nit= (long int)(ITER);
	nop= ((n2* n2)* n6);
	OPS= (float)(nop);
	RMEG= RMEG/(float)(ITER);

/* allocate arrays (with timing) */
	t1= ticktock();
	u= mat_alloc(1,NLEN,1,NLEN);
	f= mat_alloc(1,NLEN,1,NLEN);
	r= mat_alloc(1,NLEN,1,NLEN);
	t2= ticktock();

	times[ir]= t2- t1- TOVH;
	flops[ir]= 0.0;
	crout[ir]= "alloc";
	ir++;

/* initialization (with timing) */
	t1= ticktock();
	init(1,NLEN,1,NLEN,u,f);
	t2= ticktock();

	times[ir]= t2- t1- TOVH;
	flops[ir]= 0.0;
	crout[ir]= " init";
	ir++;

/* do the work with timing */

	t1= ticktock();
	work(1,NLEN,1,NLEN,u,f);
	t2= ticktock();

	times[ir]= t2- t1- TOVH;
	flops[ir]= OPS/ (times[ir]* RMEG);
	crout[ir]= " work";
	ir++;

/* calculate residual (with timing) */

	t1= ticktock();
	result= resid(1,NLEN,1,NLEN,u,f,r);
	t2= ticktock();

	times[ir]= t2- t1- TOVH;
	flops[ir]= 0.0;
	crout[ir]= "resid";
	ir++;

/* print fields in a matlab format */
	if(NLEN <= DEFAULTLEN){
		t1= ticktock();
		matlab_out(1,NLEN,1,NLEN,"rhs.dat",f);
		matlab_out(1,NLEN,1,NLEN,"sol.dat",u);
		matlab_out(1,NLEN,1,NLEN,"res.dat",r);
		t2= ticktock();

		times[ir]= t2- t1- TOVH;
		flops[ir]= 0.0;
		crout[ir]= "matlb";
		ir++;
	}

/* print results in a nice format */
	print_result(numprocs, times, flops, crout, result, ir, NLEN, NSPACE);

/* free the allocated memory space cleanly */
	mat_free(u,1,NLEN,1,NLEN);
	mat_free(f,1,NLEN,1,NLEN);
	mat_free(r,1,NLEN,1,NLEN);

} /* end of main */
