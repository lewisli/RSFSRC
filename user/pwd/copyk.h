/* This file is automatically generated. DO NOT EDIT! */

#ifndef _copyk_h
#define _copyk_h


void copyk_init(int nk1 /* number of components */,
		int n1  /* size of one component */);
/*< initialize >*/


void copyk_lop (bool adj, bool add, int nx, int ny, float* xx, float* yy);
/*< linear operator >*/

#endif
