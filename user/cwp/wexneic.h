/* This file is automatically generated. DO NOT EDIT! */

#ifndef _wexneic_h
#define _wexneic_h


#include <rsf.h>
#include <math.h>
/*^*/
#ifdef _OPENMP
#include <omp.h>
#include "omputil.h"
#endif
/*^*/
#include "wex.h"
#include "wexneic.h"
/*^*/
#ifdef SF_HAS_COMPLEX_H
#define cWGH(a,b,c)  (+1.*(conjf(a)*b)*c)
#define cAWGH(a,b,c) (+1.*(a*b)*c)
#define cCOR(a,b) (conjf(a)*b)
#define cACOR(a,b) (a*b)
#define cMUL(a,b) (a*b) 
#else
#define cWGH(a,b,c) (+1.*sf_cmul((sf_cmul(conjf(a),b)),c))
#define cAWGH(a,b,c) (+1.*sf_cmul((sf_cmul(a,b)),c))
#define cCOR(a,b) (sf_cmul(conjf(a),b))
#define cACOR(a,b) (sf_cmul(a,b))
#define cMUL(a,b) (sf_cmul(a,b))
#endif


/*------------------------------------------------------------*/
wexncip3d wexncip_init(wexcub3d cub,
                        int  nhx_,
                        int  nhy_,
                        int  nhz_,
                        int  nht_,
                        int  nhx2_,
                        int  nhy2_,
                        int  nhz2_,
                        int  nht2_,
                        int   nc_,
		       float  dhx_,
		       float  dhy_,
		       float  dhz_,
		       float  dht_,
		       float  oht_,
		       sf_file Fc,
		       sf_file Fdx,
		       sf_file Fdy,
		       int eic);
/*< initialize I.C. >*/


/*------------------------------------------------------------*/
void wexncip_close(wexncip3d cip, int eic);
/*< free allocated storage >*/


/*------------------------------------------------------------*/
void wexncip_for(wexcub3d  cub,
                 wexncip3d cip,
                  sf_file wfls,
                  sf_file wflr,
                  sf_file imag,
                  int eic,
                  int rep,
                  int cjg
         );
/*< E.I.C >*/

#endif
