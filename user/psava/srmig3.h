/* This file is automatically generated. DO NOT EDIT! */

#ifndef _srmig3_h
#define _srmig3_h


#include <rsf.h>


#include "weutil.h"


/*------------------------------------------------------------*/
cub3d srmig3_cube(bool    verb_,
		  sf_axis amx_,
		  sf_axis amy_,
		  sf_axis amz_,
		  sf_axis alx_,
		  sf_axis aly_,
		  sf_axis aw_,
		  sf_axis ae_,
		  float   eps_,
		  int     ompnth_,
		  int     ompchunk_
    );
/*< initialize SR migration space >*/


/*------------------------------------------------------------*/
ssroperator3d srmig3_init(cub3d cub);
/*< initialize SR migration >*/


/*------------------------------------------------------------*/
void srmig3_close(ssroperator3d weop);
/*< free allocated storage >*/


/*------------------------------------------------------------*/
void srmig3(ssroperator3d weop,
	    cub3d cub,
	    ssr3d ssr,
	    tap3d tap,
	    slo3d s_s,
	    slo3d s_r,
	    img3d img,
	    sf_fslice swfl /* source   data [nw][ny][nx] */,
	    sf_fslice rwfl /* receiver data [nw][ny][nx] */,
	    sf_fslice imag /*         image [nz][ny][nx] */,
	    sf_fslice cigs,
	    void (*imop)(cub3d,img3d,int,int)
    );
/*< apply SR migration >*/

#endif
