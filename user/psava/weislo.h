/* This file is automatically generated. DO NOT EDIT! */

#ifndef _weislo_h
#define _weislo_h


#include "weiutl.h"


/*------------------------------------------------------------*/
weislo3d weislo_init(weicub3d cub,
		     sf_file  Fslo  /* slowness file */
    );
/*< initialize slowness >*/


/*------------------------------------------------------------*/
weislo3d weizoslo_init(weicub3d cub,
                     sf_file  Fslo  /* slowness file */
    );
/*< initialize slowness >*/


/*------------------------------------------------------------*/
void weislo_inp(weicub3d cub,
		sf_file Fslo);
/*< input slow dimensions >*/


/*------------------------------------------------------------*/
void weislo_report(weislo3d slo);
/*< report slo parameters >*/


/*------------------------------------------------------------*/
int weislo(int nr           /* maximum number of references */, 
	  float ds         /* minimum slowness separation */, 
	  int ns           /* number of slownesses */, 
	  const float* ss  /* [ns] slowness array */, 
	  float* sr        /* [nr] reference slownesses squared */);
/*< compute reference slownesses, return their number >*/


/*------------------------------------------------------------*/
void weislo_close(weislo3d slo);
/*< close slowness >*/

#endif
