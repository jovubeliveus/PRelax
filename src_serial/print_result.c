/*****************************************************************

 NAME:
	print_result

 FUNCTION:
	print the results of timing measurements in a nice format
	(part of the c mtrix multiply benchmark)

 SYNTAX:
	print_result(float.arr, float.arr, char.arr, int, int, int)

 ON INPUT:
	times:	array of timings			float
	flops:	array of mflops rates			float
	crout:	array of routine strings		char
	ir:	no. of tested routines (max. 10)	int
	n:	rank of matrix				int
	NSPACE:	memory allocated			int

 ON OUTPUT:
	nice output of all these values on stdout

 CALLS:

 COMMENTS:

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j. behrens	6/93
	2. changed for PPtemplate	j. behrens	3/99

*****************************************************************/

#include <stdio.h>

void print_result(numpr, times, flops, crout, result, ir, n, NSPACE)
float times[], flops[];
char *crout[];
float result;
int numpr, ir, n, NSPACE;
{

	int i;

/* set up strings */
	char *STRING1= "|================================================|";
	char *STRING2= "|------------------------------------------------|";

/* print header info */
	fprintf(stdout,"%s \n", STRING1);
	fprintf(stdout,"|      program for testing parallelization       |\n");
	fprintf(stdout,"|                 using OpenMP                   |\n");
	fprintf(stdout,"|           (c) j. behrens 1999-2021             |\n");
	fprintf(stdout,"|                                                |\n");
	fprintf(stdout,"|           number of processors:%4i            |\n",numpr);
	fprintf(stdout,"|           size of arrays:%10i            |\n",n);
	fprintf(stdout,"|      allocated memory in kbytes:%8i       |\n",(NSPACE/1024));
	fprintf(stdout,"|              residual: %10.4e              |\n",result);
	fprintf(stdout,"%s \n", STRING1);

/* print results from routine measurements */
	for(i=0; i<ir; i++) {
		fprintf(stdout,"|    results for routine %s                   |\n",crout[i]);
		fprintf(stdout,"|    time (s): %10.4e mflop/s: %10.4e    |\n", times[i], flops[i]);
		fprintf(stdout,"%s \n", STRING2);
	}
} /* end of print_result */
