/*****************************************************************

 NAME:
	ticktock

 FUNCTION:
	timing routine

 SYNTAX:
	float= ticktock();

 ON INPUT:

 ON OUTPUT:
	ticktock:	time in seconds		float

 CALLS:
	clock

 COMMENTS:

 LIBRARIES:

 REFERENCES:

 VERSION(S):
	1. original version		j. behrens	6/93
	2. timing with getrusage	j.behrens	6/93

*****************************************************************/

#ifdef GETRUS          /* definitions for the getrusage version */
#include <sys/time.h>
#include <sys/resource.h>

struct rusage rusage;
#else                      /* definitions for the times version */
#include <sys/times.h>
#include <sys/param.h>
#endif

float ticktock()
{
	float tmp;

#ifdef GETRUS          /* definitions for the getrusage version */
/* take the time from routine getrusage */
	getrusage(RUSAGE_SELF,&rusage);
	tmp= (float)(rusage.ru_utime.tv_sec)+ (float)(rusage.ru_utime.tv_usec) * 1.0e-06;
	return (tmp);
#else                      /* definitions for the times version */

	struct tms counter;

                            /* take the time from routine times */
	tmp = (float)times(&counter)/(float)HZ;    
	return (tmp);
#endif

} /* end of ticktock */
