#ifndef __ACDPMLGFDM2__
#define __ACDPMLGFDM2__

#include "acdpml.hh"

/*--- 2nd order deriv time step functions --------------------------*/
int acdpml_tsfm2(RDOM * dd, RDOM *d0, RDOM * d, RDOM * r, int ia, void * fdpars);

/*--- 2nd order deriv adjoint time step functions --------------------------*/
int acdpml_tsam2(RDOM * db, RDOM *b,  RDOM * d, RDOM * r, int ia, void * fdpars);

  
#endif
