/*****************************************************************

 NAME:
	matlab_out

 FUNCTION:
	open a file and print array in matlab compatible format.

 SYNTAX:
	matlab_out(int, int, int, int, string, float.arr);

 ON INPUT:
	nb:	beginning index (col)	int
	ne:	ending index (col)	int
	mb:	beginning index (row)	int
	me:	ending index (row)	int
	fname:	file name		char
	v:	array 			float

 ON OUTPUT:

 CALLS:

 COMMENTS:

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j. behrens	3/99

*****************************************************************/

#include <stdio.h>

void matlab_out(int nb, int ne, int mb, int me, char* fname, float **v)
{
	int i, j;
	FILE *fp;

/* open output file */
	if((fp= fopen(fname,"w"))!=NULL){

/* print the grid size */
		fprintf(fp,"%d\n",(ne-nb+1));
		fprintf(fp,"%d\n",(me-mb+1));

/* print loop */
		for(i=nb; i<=ne; i++) {
		for(j=mb; j<=me; j++) {
			fprintf(fp,"%15.6e\n",v[i][j]);
		}
		}

/* close output file */
		fclose(fp);
	}

} /* end of matlab_out */

