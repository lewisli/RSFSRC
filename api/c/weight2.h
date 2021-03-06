/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_weight2_h
#define _sf_weight2_h


#include "_bool.h"


void sf_weight2_init(int nw1   /* number of components */, 
		     int n     /* model size */, 
		     float *ww /* weight [nw*n] */);
/*< initialize >*/


void sf_weight2_close(void);
/*< free allocated storage >*/


void sf_weight2_lop (bool adj, bool add, int nx, int ny, float* xx, float* yy);
/*< linear operator >*/

#endif
