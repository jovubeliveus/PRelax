/*****************************************************************

 NAME:
	utils

 FUNCTION:
	contains some utility functions (analogue to Num. Recipes)

 SYNTAX:
 	float.ptr    = vec_alloc(int,int);
	float.ptr.ptr= mat_alloc(int,int,int,int);
	vec_free(float.ptr,int,int);
	mat_free(float.ptr.ptr,int,int,int,int);
	prerror(int,char.arr);

 ON INPUT:
	vec_alloc:
	nl:		lower array bound	int
	nh:		higher array bound	int

	vec_free:
	m:		ptr to array		float
	nl:		lower array bound	int
	nh:		higher array bound	int

	mat_alloc:
	nl:		lower array bound (cols)	int
	nh:		higher array bound (cols)	int
	ml:		lower array bound (rows)	int
	mh:		higher array bound (rows)	int

	mat_free:
	m:		ptr to array			float
	nl:		lower array bound (cols)	int
	nh:		higher array bound (cols)	int
	ml:		lower array bound (rows)	int
	mh:		higher array bound (rows)	int

	prerror:
	ierr:		error/warning code	int
	errortxt:	error text		char

 ON OUTPUT:
	vec_alloc:
	vec_alloc:	pointer to vector	float

	mat_alloc:
	mat_alloc:	pointer to matrix	float

 CALLS:

 COMMENTS:
	prerror exits if the error flag 'ierr' is 
	greater then 10. it then prints an ERROR message,
	otherwise it prints a WARNING message.

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j.behrens	6/93
	2. changed for PPtemplate	j.behrens	3/99

*****************************************************************/

#include <stdio.h>
#ifdef MACOSX
#include <stdlib.h>
#else
#include <malloc.h>
#endif

void prerror(ierror, error_txt)
int ierror;
char error_txt[];
{
	if(ierror <= 10) 
		fprintf(stderr,"WARNING: %3i : %s \n", ierror, error_txt);
	else {
		fprintf(stderr,"ERROR: %3i : %s \n", ierror, error_txt);
		fprintf(stderr,"         ... exiting now ... \n");
		exit (1);
	}

} /* end of prerror */

/*****************************************************************/

float *vec_alloc(int nl, int nh)
{
	int i;
	float *m;

/* allocate vector an set pointer */
	if((m= (float *) calloc((size_t) (nh- nl+ 1), sizeof(double))) == NULL)
	prerror(23," allocation failed in vec_alloc! ");
	m -= nl;
	return m;

} /* end of vec_alloc */

/*****************************************************************/

void vec_free(float *m, int nl, int nh)
{
	int i;

/* free the whole space occupied by vector */
	free((char*) (m+ nl));

} /* end of vec_free */

/*****************************************************************/

float **mat_alloc(int nl, int nh, int ml, int mh)
{
	int i;
	float **m;

/* allocate pointers to the rows of the matrix */
	if((m= (float **) calloc((size_t) (nh- nl+ 1), (size_t) sizeof(double))) == NULL)
	prerror(22," allocation failed in mat_alloc! ");
	m -= nl;

/* allocate rows an set pointers to them */
	for(i=nl; i<=nh; i++) {
		if((m[i]= (float *) calloc((size_t) (mh- ml+ 1), (size_t) sizeof(double))) == NULL)
                prerror(22," allocation failed in mat_alloc! ");
		m[i] -= ml;
	}
	return m;

} /* end of mat_alloc */

/*****************************************************************/

void mat_free(float **m, int nl, int nh, int ml, int mh)
{
	int i;

/* free the whole space occupied by the matrix */
	for(i=nh; i>=nl; i--) 
		free((char*) (m[i]+ ml));
	free((char*) (m+ nl));

} /* end of mat_free */
