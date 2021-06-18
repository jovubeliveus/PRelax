/*****************************************************************

 NAME:
	resid

 FUNCTION:
	calculate the residual and the inifinity-norm of it.

 SYNTAX:
	float= resid(int, int, int, int, float.arr, float.arr, float.arr);

 ON INPUT:
	nb:	beginning index (col)	int
	ne:	ending index (col)	int
	mb:	beginning index (row)	int
	me:	ending index (row)	int
	u:	array (solution)	float
	rhs:	array (right hand)	float

 ON OUTPUT:
	res:	array (residual)	float
	resid:	infinity norm of res	float

 CALLS:

 COMMENTS:
 	the residual of a poisson equation [Laplace] x = rhs
	with x=0 on the boundary, rhs=1 (const) is calculated

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j. behrens	3/99

*****************************************************************/

#include <math.h>
#include "global.h"
#define ABS(x)	((x) < 0 ? -(x) : (x))
#define MAX(a,b) ((a) > (b)) ?  (a) :  (b)

float resid(int nb, int ne, int mb, int me, float **u, float **rhs, float **res)
{
	int i, j;
	float r=0.0;
	float tmp1;

/* initialize constants */
	tmp1= 1./(DX*DX);

/* initialize matrices with some values */
	for(i=nb+1; i<ne; i++) {
		for(j=mb+1; j<me; j++) {
			res[i][j]= rhs[i][j]- tmp1*(4.* u[i][j]- u[i-1][j]- u[i+1][j]- u[i][j-1]- u[i][j+1]);
			r= MAX(ABS(res[i][j]),r);
		}
	}
	for(i=nb+1; i<ne; i++) {
		res[i][mb]= 0.0; res[i][me]= 0.0;
	}
	for(j=mb+1; j<me; j++) {
		res[nb][j]= 0.0; res[ne][j]= 0.0;
	}

	return r;

} /* end of resid */

