/*****************************************************************

 NAME:
	init

 FUNCTION:
	initialize the matrices

 SYNTAX:
	init(int, int, int, int, float.arr, float.arr);

 ON INPUT:
	nb:	beginning index (col)	int
	ne:	ending index (col)	int
	mb:	beginning index (row)	int
	me:	ending index (row)	int
	u:	array (unnkown)		float
	rhs:	array (right hand)	float

 ON OUTPUT:
	u:	initialized array	float
	rhs:	initialized array	float


 CALLS:

 COMMENTS:
 	this initializes a poisson equation [Laplace] x = rhs
	with x=0 on the boundary, rhs=1 (const).

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j. behrens	6/93
	2. changed for PPtemplate	j. behrens	3/99

*****************************************************************/

#include <math.h>
#include "global.h"

void init(int nb, int ne, int mb, int me, float **u, float **rhs)
{
	int i, j;
	float x, y, x2, y2;

/* initialize matrices with some values */
	for(i=nb; i<=ne; i++) {
		x= (i-1)* DX; x2= x*x;
		for(j=mb; j<=me; j++) {
			y= (j-1)* DX; y2= y*y;
			u[i][j]= 0.0; rhs[i][j]= 2.* (x+ y- x2- y2);
		}
	}
/*	y= (mb-1)* DX; y2= (me-1)* DX;
	for(i=nb; i<=ne; i++) {
		x= (i-1)* DX;
		u[i][mb]= x* y* (1.-x)* (1.-y);
		u[i][me]= x* y2* (1.-x)* (1.-y2);
	}
	x= (nb-1)* DX; x2= (ne-1)* DX;
	for(j=mb; j<=me; j++) {
		y= (j-1)* DX;
		u[nb][j]= x* y* (1.-x)* (1.-y);
		u[ne][j]= x2* y* (1.-x2)* (1.-y);
	} */

} /* end of init */
