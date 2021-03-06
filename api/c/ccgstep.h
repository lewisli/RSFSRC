/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_ccgstep_h
#define _sf_ccgstep_h


#include "_bool.h"
#include "c99.h"


void sf_ccgstep( bool forget             /* restart flag */, 
		 int nx                  /* model size */, 
		 int ny                  /* data size */, 
		 sf_complex* x        /* current model [nx] */,  
		 const sf_complex* g  /* gradient [nx] */, 
		 sf_complex* rr       /* data residual [ny] */,
		 const sf_complex* gg /* conjugate gradient [ny] */);
/*< Step of Claerbout's conjugate-gradient iteration for complex operators. 
  The data residual is rr = A x - dat
>*/


void sf_ccgstep_close (void);
/*< Free allocated space. >*/

#endif
