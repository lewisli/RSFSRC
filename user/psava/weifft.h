/* This file is automatically generated. DO NOT EDIT! */

#ifndef _weifft_h
#define _weifft_h


#include <rsf.h>


#include "weiutl.h"


/*------------------------------------------------------------*/
weifft2d weifft_init(weicub3d cub,
		      int n1_, 
		      int n2_);
/*< initialize OMP fft >*/


/*------------------------------------------------------------*/
void weifft_close(weifft2d fft);
/*< close OMP fft >*/


/*------------------------------------------------------------*/
void weifft(bool inv          /* inverse/forward flag */, 
	     kiss_fft_cpx **pp /* [1...n2][1...n1] */,
	     weifft2d fft);
/*< apply 2-D FFT >*/

#endif
