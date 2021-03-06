/*        Generated by TAPENADE     (INRIA, Tropics team)
    Tapenade 3.7 (r4786) - 21 Feb 2013 15:53
*/
#include "cstd.h"

/*
  Differentiation of acdpml_2d_8_d in forward (tangent) mode:
   variations   of useful results: **phi0d **upd **phi0 **up **phi1d
                **phi1
   with respect to varying inputs: **ucd **phi0d **upd **csq **uc
                **phi0 **up **phi1d **phi1
   RW status of diff variables: **ucd:in **phi0d:in-out **upd:in-out
                **csq:in **uc:in **phi0:in-out **up:in-out **phi1d:in-out
                **phi1:in-out
   Plus diff mem management of: ucd:in *ucd:in phi0d:in *phi0d:in
                upd:in *upd:in csq:in *csq:in uc:in *uc:in phi0:in
                *phi0:in up:in *up:in phi1d:in *phi1d:in phi1:in
                *phi1:in


  Differentiation of acdpml_2d_8 in forward (tangent) mode:
   variations   of useful results: **phi0 **up **phi1
   with respect to varying inputs: **csq **uc **phi0 **up **phi1
   RW status of diff variables: **csq:in **uc:in **phi0:in-out
                **up:in-out **phi1:in-out
   Plus diff mem management of: csq:in *csq:in uc:in *uc:in phi0:in
                *phi0:in up:in *up:in phi1:in *phi1:in
*/
void acdpml_2d_8_d_d(float **uc, float **ucd0, float **ucd, float **ucdd, 
        float **up, float **upd0, float **upd, float **updd, float **csq, 
        float **csqd0, float **csqd, float **phi1, float **phi1d0, float **
        phi1d, float **phi1dd, float **phi0, float **phi0d0, float **phi0d, 
        float **phi0dd, float *dp1, float *dp0, float *di, float dt, int *s, 
        int *e, float c0, float *c1, float *c2, float *c3, float *c4, int *lbc
        , int *rbc) {
    /* current field
    // previous field
    // csq
    // phi1
    // phi0
    // damping profile zeta_x
    // damping profile zeta_x
    // start index
    // end index */
    int i1, i0;
    float lap, lapd0, lapd, lapdd, cff, cffuc, cffup, cff1, cff0;
    float tmp, tmpd0, tmpd, tmpux, tmpuxd0, tmpuxd, tmpuxdd, tmpuz, tmpuzd0, tmpuzd, tmpuzdd;
    /*fprintf(stderr, "dp0[%d] = %f\n",e[0], dp0[e[0]]);
    // PML
    //fprintf(stderr, " after computing Du_x Du_z acdpml_2d_2!!!\n");
    // \phi separate loops along boundary !!!!!!!!!!!!!!!! csq and damp profile
    // compute interior of the domain
    // update wavefield up */
    for (i1 = s[1]; i1 < e[1]+1; ++i1)
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            lap = c0*uc[i1][i0] + c1[0]*(uc[i1][i0+1]+uc[i1][i0-1]) + c1
            [1]*(uc[i1+1][i0]+uc[i1-1][i0]) + c2[0]*(uc[i1][i0+2]+uc[i1][i0-2]
            ) + c2[1]*(uc[i1+2][i0]+uc[i1-2][i0]) + c3[0]*(uc[i1][i0+3]+uc[i1]
            [i0-3]) + c3[1]*(uc[i1+3][i0]+uc[i1-3][i0]) + c4[0]*(uc[i1][i0+4]+
            uc[i1][i0-4]) + c4[1]*(uc[i1+4][i0]+uc[i1-4][i0]);
            lapd0 = c0*ucd0[i1][i0] + c1[0]*(ucd0[i1][i0+1]+ucd0[i1][i0-
            1]) + c1[1]*(ucd0[i1+1][i0]+ucd0[i1-1][i0]) + c2[0]*(ucd0[i1][i0+2
            ]+ucd0[i1][i0-2]) + c2[1]*(ucd0[i1+2][i0]+ucd0[i1-2][i0]) + c3[0]*
            (ucd0[i1][i0+3]+ucd0[i1][i0-3]) + c3[1]*(ucd0[i1+3][i0]+ucd0[i1-3]
            [i0]) + c4[0]*(ucd0[i1][i0+4]+ucd0[i1][i0-4]) + c4[1]*(ucd0[i1+4][
            i0]+ucd0[i1-4][i0]);
            lapd = c0*ucd[i1][i0] + c1[0]*(ucd[i1][i0+1]+ucd[i1][i0-1]) 
            + c1[1]*(ucd[i1+1][i0]+ucd[i1-1][i0]) + c2[0]*(ucd[i1][i0+2]+ucd[
            i1][i0-2]) + c2[1]*(ucd[i1+2][i0]+ucd[i1-2][i0]) + c3[0]*(ucd[i1][
            i0+3]+ucd[i1][i0-3]) + c3[1]*(ucd[i1+3][i0]+ucd[i1-3][i0]) + c4[0]
            *(ucd[i1][i0+4]+ucd[i1][i0-4]) + c4[1]*(ucd[i1+4][i0]+ucd[i1-4][i0
            ]);
            lapdd = c0*ucdd[i1][i0] + c1[0]*(ucdd[i1][i0+1]+ucdd[i1][i0-
            1]) + c1[1]*(ucdd[i1+1][i0]+ucdd[i1-1][i0]) + c2[0]*(ucdd[i1][i0+2
            ]+ucdd[i1][i0-2]) + c2[1]*(ucdd[i1+2][i0]+ucdd[i1-2][i0]) + c3[0]*
            (ucdd[i1][i0+3]+ucdd[i1][i0-3]) + c3[1]*(ucdd[i1+3][i0]+ucdd[i1-3]
            [i0]) + c4[0]*(ucdd[i1][i0+4]+ucdd[i1][i0-4]) + c4[1]*(ucdd[i1+4][
            i0]+ucdd[i1-4][i0]);
            cff = 1.0/(1.0+(dp1[i1]+dp0[i0])*dt/2.0);
            cffuc = (2.0-dp1[i1]*dp0[i0]*dt*dt)*cff;
            cffup = ((dp1[i1]+dp0[i0])/2.0*dt-1.0)*cff;
            cff1 = dt*dt/2.0/di[1]*cff;
            cff0 = dt*dt/2.0/di[0]*cff;
            updd[i1][i0] = cffuc*ucdd[i1][i0] + cffup*updd[i1][i0] + cff*(csqd
                [i1][i0]*lapd0+csqd0[i1][i0]*lapd+csq[i1][i0]*lapdd) + cff1*(
                phi1dd[i1][i0-1]+phi1dd[i1][i0]-phi1dd[i1-1][i0-1]-phi1dd[i1-1
                ][i0]) + cff0*(phi0dd[i1-1][i0]+phi0dd[i1][i0]-phi0dd[i1-1][i0
                -1]-phi0dd[i1][i0-1]);
            upd[i1][i0] = cffuc*ucd[i1][i0] + cffup*upd[i1][i0] + cff*(csqd[i1
                ][i0]*lap+csq[i1][i0]*lapd) + cff1*(phi1d[i1][i0-1]+phi1d[i1][
                i0]-phi1d[i1-1][i0-1]-phi1d[i1-1][i0]) + cff0*(phi0d[i1-1][i0]
                +phi0d[i1][i0]-phi0d[i1-1][i0-1]-phi0d[i1][i0-1]);
            upd0[i1][i0] = cffuc*ucd0[i1][i0] + cffup*upd0[i1][i0] + cff*(
                csqd0[i1][i0]*lap+csq[i1][i0]*lapd0) + cff1*(phi1d0[i1][i0-1]+
                phi1d0[i1][i0]-phi1d0[i1-1][i0-1]-phi1d0[i1-1][i0]) + cff0*(
                phi0d0[i1-1][i0]+phi0d0[i1][i0]-phi0d0[i1-1][i0-1]-phi0d0[i1][
                i0-1]);
            up[i1][i0] = cffuc*uc[i1][i0] + cffup*up[i1][i0] + cff*csq[i1][i0]
                *lap + cff1*(phi1[i1][i0-1]+phi1[i1][i0]-phi1[i1-1][i0-1]-phi1
                [i1-1][i0]) + cff0*(phi0[i1-1][i0]+phi0[i1][i0]-phi0[i1-1][i0-
                1]-phi0[i1][i0-1]);
        }
    for (i1 = s[1]; i1 < e[1]; ++i1)
        for (i0 = s[0]; i0 < e[0]; ++i0) {
            cff1 = (2.0-dt*dp1[i1])/(2.0+dt*dp1[i1]);
            cff0 = (2.0-dt*dp0[i0])/(2.0+dt*dp0[i0]);
            tmp = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+
            1])/4.0*2.0*dt;
            tmpd0 = 2.0*dt*(csqd0[i1][i0]+csqd0[i1+1][i0]+csqd0[i1][i0+1
            ]+csqd0[i1+1][i0+1])/4.0;
            tmpd = 2.0*dt*(csqd[i1][i0]+csqd[i1+1][i0]+csqd[i1][i0+1]+
            csqd[i1+1][i0+1])/4.0;
            tmpux = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]
            +up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])/4.0/di[1]*(
            dp0[i0]-dp1[i1])/(2.0+dt*dp1[i1]);
            tmpuxd0 = (dp0[i0]-dp1[i1])*(ucd0[i1+1][i0]+ucd0[i1+1][i0+1]
            -ucd0[i1][i0]-ucd0[i1][i0+1]+upd0[i1+1][i0]+upd0[i1+1][i0+1]-upd0[
            i1][i0]-upd0[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
            tmpuxd = (dp0[i0]-dp1[i1])*(ucd[i1+1][i0]+ucd[i1+1][i0+1]-
            ucd[i1][i0]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0
            ]-upd[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
            tmpuxdd = (dp0[i0]-dp1[i1])*(ucdd[i1+1][i0]+ucdd[i1+1][i0+1]
            -ucdd[i1][i0]-ucdd[i1][i0+1]+updd[i1+1][i0]+updd[i1+1][i0+1]-updd[
            i1][i0]-updd[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
            tmpuz = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]
            +up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])/4.0/di[0]*(
            dp1[i1]-dp0[i0])/(2.0+dt*dp0[i0]);
            tmpuzd0 = (dp1[i1]-dp0[i0])*(ucd0[i1][i0+1]+ucd0[i1+1][i0+1]
            -ucd0[i1][i0]-ucd0[i1+1][i0]+upd0[i1][i0+1]+upd0[i1+1][i0+1]-upd0[
            i1][i0]-upd0[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
            tmpuzd = (dp1[i1]-dp0[i0])*(ucd[i1][i0+1]+ucd[i1+1][i0+1]-
            ucd[i1][i0]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0
            ]-upd[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
            tmpuzdd = (dp1[i1]-dp0[i0])*(ucdd[i1][i0+1]+ucdd[i1+1][i0+1]
            -ucdd[i1][i0]-ucdd[i1+1][i0]+updd[i1][i0+1]+updd[i1+1][i0+1]-updd[
            i1][i0]-updd[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
            phi1dd[i1][i0] = cff1*phi1dd[i1][i0] + tmpuxdd*tmp + tmpuxd*tmpd0 
                + tmpd*tmpuxd0;
            phi1d[i1][i0] = cff1*phi1d[i1][i0] + tmpuxd*tmp + tmpux*tmpd;
            phi1d0[i1][i0] = cff1*phi1d0[i1][i0] + tmpuxd0*tmp + tmpux*tmpd0;
            phi1[i1][i0] = phi1[i1][i0]*cff1 + tmpux*tmp;
            phi0dd[i1][i0] = cff0*phi0dd[i1][i0] + tmpuzdd*tmp + tmpuzd*tmpd0 
                + tmpd*tmpuzd0;
            phi0d[i1][i0] = cff0*phi0d[i1][i0] + tmpuzd*tmp + tmpuz*tmpd;
            phi0d0[i1][i0] = cff0*phi0d0[i1][i0] + tmpuzd0*tmp + tmpuz*tmpd0;
            phi0[i1][i0] = phi0[i1][i0]*cff0 + tmpuz*tmp;
        }
    i1 = s[1] - 1;
    i0 = s[0] - 1;
    cff1 = (2.0-dt*dp1[i1])/(2.0+dt*dp1[i1]);
    cff0 = (2.0-dt*dp0[i0])/(2.0+dt*dp0[i0]);
    tmpux = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[i1+1
    ][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])/4.0/di[1]*(dp0[i0]-dp1[i1])/
    (2.0+dt*dp1[i1]);
    tmpuxd0 = (dp0[i0]-dp1[i1])*(ucd0[i1+1][i0]+ucd0[i1+1][i0+1]-ucd0[i1
    ][i0]-ucd0[i1][i0+1]+upd0[i1+1][i0]+upd0[i1+1][i0+1]-upd0[i1][i0]-upd0[i1]
    [i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
    tmpuxd = (dp0[i0]-dp1[i1])*(ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][i0
    ]-ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1][i0+1])/(
    4.0*di[1])/(2.0+dt*dp1[i1]);
    tmpuxdd = (dp0[i0]-dp1[i1])*(ucdd[i1+1][i0]+ucdd[i1+1][i0+1]-ucdd[i1
    ][i0]-ucdd[i1][i0+1]+updd[i1+1][i0]+updd[i1+1][i0+1]-updd[i1][i0]-updd[i1]
    [i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
    tmpuz = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[i1][
    i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])/4.0/di[0]*(dp1[i1]-dp0[i0])/
    (2.0+dt*dp0[i0]);
    tmpuzd0 = (dp1[i1]-dp0[i0])*(ucd0[i1][i0+1]+ucd0[i1+1][i0+1]-ucd0[i1
    ][i0]-ucd0[i1+1][i0]+upd0[i1][i0+1]+upd0[i1+1][i0+1]-upd0[i1][i0]-upd0[i1+
    1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
    tmpuzd = (dp1[i1]-dp0[i0])*(ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][i0
    ]-ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1+1][i0])/(
    4.0*di[0])/(2.0+dt*dp0[i0]);
    tmpuzdd = (dp1[i1]-dp0[i0])*(ucdd[i1][i0+1]+ucdd[i1+1][i0+1]-ucdd[i1
    ][i0]-ucdd[i1+1][i0]+updd[i1][i0+1]+updd[i1+1][i0+1]-updd[i1][i0]-updd[i1+
    1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
    phi1dd[i1][i0] = cff1*phi1dd[i1][i0] + 2.0*dt*(tmpuxdd*csq[i1+1][i0+1]+
        tmpuxd*csqd0[i1+1][i0+1]+csqd[i1+1][i0+1]*tmpuxd0);
    phi1d[i1][i0] = cff1*phi1d[i1][i0] + 2.0*dt*(tmpuxd*csq[i1+1][i0+1]+tmpux*
        csqd[i1+1][i0+1]);
    phi1d0[i1][i0] = cff1*phi1d0[i1][i0] + 2.0*dt*(tmpuxd0*csq[i1+1][i0+1]+
        tmpux*csqd0[i1+1][i0+1]);
    phi1[i1][i0] = phi1[i1][i0]*cff1 + tmpux*2.0*dt*csq[i1+1][i0+1];
    phi0dd[i1][i0] = cff0*phi0dd[i1][i0] + 2.0*dt*(tmpuzdd*csq[i1+1][i0+1]+
        tmpuzd*csqd0[i1+1][i0+1]+csqd[i1+1][i0+1]*tmpuzd0);
    phi0d[i1][i0] = cff0*phi0d[i1][i0] + 2.0*dt*(tmpuzd*csq[i1+1][i0+1]+tmpuz*
        csqd[i1+1][i0+1]);
    phi0d0[i1][i0] = cff0*phi0d0[i1][i0] + 2.0*dt*(tmpuzd0*csq[i1+1][i0+1]+
        tmpuz*csqd0[i1+1][i0+1]);
    phi0[i1][i0] = phi0[i1][i0]*cff0 + tmpuz*2.0*dt*csq[i1+1][i0+1];
    /* compute i1=s[1]-1 */
    i1 = s[1] - 1;
    for (i0 = s[0]; i0 < e[0]+1; ++i0) {
        cff1 = (2.0-dt*dp1[i1])/(2.0+dt*dp1[i1]);
        cff0 = (2.0-dt*dp0[i0])/(2.0+dt*dp0[i0]);
        tmpuxdd = (dp0[i0]-dp1[i1])*(ucdd[i1+1][i0]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1][i0+1]+updd[i1+1][i0]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd = (dp0[i0]-dp1[i1])*(ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1][i0
            +1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd0 = (dp0[i0]-dp1[i1])*(ucd0[i1+1][i0]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1][i0+1]+upd0[i1+1][i0]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpux = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[i1+1][
            i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])/4.0/di[1]*(dp0[i0]-dp1
            [i1])/(2.0+dt*dp1[i1]);
        tmpuzdd = (dp1[i1]-dp0[i0])*(ucdd[i1][i0+1]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1+1][i0]+updd[i1][i0+1]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd = (dp1[i1]-dp0[i0])*(ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1+1][
            i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd0 = (dp1[i1]-dp0[i0])*(ucd0[i1][i0+1]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1+1][i0]+upd0[i1][i0+1]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuz = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[i1][i0
            +1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])/4.0/di[0]*(dp1[i1]-dp0
            [i0])/(2.0+dt*dp0[i0]);
        phi1dd[i1][i0] = cff1*phi1dd[i1][i0] + 2.0*dt*(tmpuxdd*csq[i1+1][i0]+
            tmpuxd*csqd0[i1+1][i0]+csqd[i1+1][i0]*tmpuxd0);
        phi1d[i1][i0] = cff1*phi1d[i1][i0] + 2.0*dt*(tmpuxd*csq[i1+1][i0]+
            tmpux*csqd[i1+1][i0]);
        phi1d0[i1][i0] = cff1*phi1d0[i1][i0] + 2.0*dt*(tmpuxd0*csq[i1+1][i0]+
            tmpux*csqd0[i1+1][i0]);
        phi1[i1][i0] = phi1[i1][i0]*cff1 + tmpux*2.0*dt*csq[i1+1][i0];
        phi0dd[i1][i0] = cff0*phi0dd[i1][i0] + 2.0*dt*(tmpuzdd*csq[i1+1][i0]+
            tmpuzd*csqd0[i1+1][i0]+csqd[i1+1][i0]*tmpuzd0);
        phi0d[i1][i0] = cff0*phi0d[i1][i0] + 2.0*dt*(tmpuzd*csq[i1+1][i0]+
            tmpuz*csqd[i1+1][i0]);
        phi0d0[i1][i0] = cff0*phi0d0[i1][i0] + 2.0*dt*(tmpuzd0*csq[i1+1][i0]+
            tmpuz*csqd0[i1+1][i0]);
        phi0[i1][i0] = phi0[i1][i0]*cff0 + tmpuz*2.0*dt*csq[i1+1][i0];
    }
    /* compute i0=s[0]-1 */
    i0 = s[0] - 1;
    for (i1 = s[1]; i1 < e[1]+1; ++i1) {
        cff1 = (2.0-dt*dp1[i1])/(2.0+dt*dp1[i1]);
        cff0 = (2.0-dt*dp0[i0])/(2.0+dt*dp0[i0]);
        tmpuxdd = (dp0[i0]-dp1[i1])*(ucdd[i1+1][i0]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1][i0+1]+updd[i1+1][i0]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd = (dp0[i0]-dp1[i1])*(ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1][i0
            +1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd0 = (dp0[i0]-dp1[i1])*(ucd0[i1+1][i0]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1][i0+1]+upd0[i1+1][i0]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpux = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[i1+1][
            i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])/4.0/di[1]*(dp0[i0]-dp1
            [i1])/(2.0+dt*dp1[i1]);
        tmpuzdd = (dp1[i1]-dp0[i0])*(ucdd[i1][i0+1]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1+1][i0]+updd[i1][i0+1]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd = (dp1[i1]-dp0[i0])*(ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1+1][
            i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd0 = (dp1[i1]-dp0[i0])*(ucd0[i1][i0+1]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1+1][i0]+upd0[i1][i0+1]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuz = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[i1][i0
            +1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])/4.0/di[0]*(dp1[i1]-dp0
            [i0])/(2.0+dt*dp0[i0]);
        phi1dd[i1][i0] = cff1*phi1dd[i1][i0] + 2.0*dt*(tmpuxdd*csq[i1][i0+1]+
            tmpuxd*csqd0[i1][i0+1]+csqd[i1][i0+1]*tmpuxd0);
        phi1d[i1][i0] = cff1*phi1d[i1][i0] + 2.0*dt*(tmpuxd*csq[i1][i0+1]+
            tmpux*csqd[i1][i0+1]);
        phi1d0[i1][i0] = cff1*phi1d0[i1][i0] + 2.0*dt*(tmpuxd0*csq[i1][i0+1]+
            tmpux*csqd0[i1][i0+1]);
        phi1[i1][i0] = phi1[i1][i0]*cff1 + tmpux*2.0*dt*csq[i1][i0+1];
        phi0dd[i1][i0] = cff0*phi0dd[i1][i0] + 2.0*dt*(tmpuzdd*csq[i1][i0+1]+
            tmpuzd*csqd0[i1][i0+1]+csqd[i1][i0+1]*tmpuzd0);
        phi0d[i1][i0] = cff0*phi0d[i1][i0] + 2.0*dt*(tmpuzd*csq[i1][i0+1]+
            tmpuz*csqd[i1][i0+1]);
        phi0d0[i1][i0] = cff0*phi0d0[i1][i0] + 2.0*dt*(tmpuzd0*csq[i1][i0+1]+
            tmpuz*csqd0[i1][i0+1]);
        phi0[i1][i0] = phi0[i1][i0]*cff0 + tmpuz*2.0*dt*csq[i1][i0+1];
    }
    /* compute i1=e[1] */
    i1 = e[1];
    for (i0 = s[0]; i0 < e[0]+1; ++i0) {
        cff1 = (2.0-dt*dp1[i1])/(2.0+dt*dp1[i1]);
        cff0 = (2.0-dt*dp0[i0])/(2.0+dt*dp0[i0]);
        tmpuxdd = (dp0[i0]-dp1[i1])*(ucdd[i1+1][i0]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1][i0+1]+updd[i1+1][i0]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd = (dp0[i0]-dp1[i1])*(ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1][i0
            +1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd0 = (dp0[i0]-dp1[i1])*(ucd0[i1+1][i0]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1][i0+1]+upd0[i1+1][i0]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpux = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[i1+1][
            i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])/4.0/di[1]*(dp0[i0]-dp1
            [i1])/(2.0+dt*dp1[i1]);
        tmpuzdd = (dp1[i1]-dp0[i0])*(ucdd[i1][i0+1]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1+1][i0]+updd[i1][i0+1]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd = (dp1[i1]-dp0[i0])*(ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1+1][
            i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd0 = (dp1[i1]-dp0[i0])*(ucd0[i1][i0+1]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1+1][i0]+upd0[i1][i0+1]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuz = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[i1][i0
            +1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])/4.0/di[0]*(dp1[i1]-dp0
            [i0])/(2.0+dt*dp0[i0]);
        phi1dd[i1][i0] = cff1*phi1dd[i1][i0] + 2.0*dt*(tmpuxdd*csq[i1][i0]+
            tmpuxd*csqd0[i1][i0]+csqd[i1][i0]*tmpuxd0);
        phi1d[i1][i0] = cff1*phi1d[i1][i0] + 2.0*dt*(tmpuxd*csq[i1][i0]+tmpux*
            csqd[i1][i0]);
        phi1d0[i1][i0] = cff1*phi1d0[i1][i0] + 2.0*dt*(tmpuxd0*csq[i1][i0]+
            tmpux*csqd0[i1][i0]);
        phi1[i1][i0] = phi1[i1][i0]*cff1 + tmpux*2.0*dt*csq[i1][i0];
        phi0dd[i1][i0] = cff0*phi0dd[i1][i0] + 2.0*dt*(tmpuzdd*csq[i1][i0]+
            tmpuzd*csqd0[i1][i0]+csqd[i1][i0]*tmpuzd0);
        phi0d[i1][i0] = cff0*phi0d[i1][i0] + 2.0*dt*(tmpuzd*csq[i1][i0]+tmpuz*
            csqd[i1][i0]);
        phi0d0[i1][i0] = cff0*phi0d0[i1][i0] + 2.0*dt*(tmpuzd0*csq[i1][i0]+
            tmpuz*csqd0[i1][i0]);
        phi0[i1][i0] = phi0[i1][i0]*cff0 + tmpuz*2.0*dt*csq[i1][i0];
    }
    /* compute i0=e[0] */
    i0 = e[0];
    for (i1 = s[1]; i1 < e[1]; ++i1) {
        cff1 = (2.0-dt*dp1[i1])/(2.0+dt*dp1[i1]);
        cff0 = (2.0-dt*dp0[i0])/(2.0+dt*dp0[i0]);
        tmpuxdd = (dp0[i0]-dp1[i1])*(ucdd[i1+1][i0]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1][i0+1]+updd[i1+1][i0]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd = (dp0[i0]-dp1[i1])*(ucd[i1+1][i0]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1][i0+1]+upd[i1+1][i0]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1][i0
            +1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpuxd0 = (dp0[i0]-dp1[i1])*(ucd0[i1+1][i0]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1][i0+1]+upd0[i1+1][i0]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1][i0+1])/(4.0*di[1])/(2.0+dt*dp1[i1]);
        tmpux = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[i1+1][
            i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])/4.0/di[1]*(dp0[i0]-dp1
            [i1])/(2.0+dt*dp1[i1]);
        tmpuzdd = (dp1[i1]-dp0[i0])*(ucdd[i1][i0+1]+ucdd[i1+1][i0+1]-ucdd[i1][
            i0]-ucdd[i1+1][i0]+updd[i1][i0+1]+updd[i1+1][i0+1]-updd[i1][i0]-
            updd[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd = (dp1[i1]-dp0[i0])*(ucd[i1][i0+1]+ucd[i1+1][i0+1]-ucd[i1][i0]-
            ucd[i1+1][i0]+upd[i1][i0+1]+upd[i1+1][i0+1]-upd[i1][i0]-upd[i1+1][
            i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuzd0 = (dp1[i1]-dp0[i0])*(ucd0[i1][i0+1]+ucd0[i1+1][i0+1]-ucd0[i1][
            i0]-ucd0[i1+1][i0]+upd0[i1][i0+1]+upd0[i1+1][i0+1]-upd0[i1][i0]-
            upd0[i1+1][i0])/(4.0*di[0])/(2.0+dt*dp0[i0]);
        tmpuz = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[i1][i0
            +1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])/4.0/di[0]*(dp1[i1]-dp0
            [i0])/(2.0+dt*dp0[i0]);
        phi1dd[i1][i0] = cff1*phi1dd[i1][i0] + 2.0*dt*(tmpuxdd*csq[i1][i0]+
            tmpuxd*csqd0[i1][i0]+csqd[i1][i0]*tmpuxd0);
        phi1d[i1][i0] = cff1*phi1d[i1][i0] + 2.0*dt*(tmpuxd*csq[i1][i0]+tmpux*
            csqd[i1][i0]);
        phi1d0[i1][i0] = cff1*phi1d0[i1][i0] + 2.0*dt*(tmpuxd0*csq[i1][i0]+
            tmpux*csqd0[i1][i0]);
        phi1[i1][i0] = phi1[i1][i0]*cff1 + tmpux*2.0*dt*csq[i1][i0];
        phi0dd[i1][i0] = cff0*phi0dd[i1][i0] + 2.0*dt*(tmpuzdd*csq[i1][i0]+
            tmpuzd*csqd0[i1][i0]+csqd[i1][i0]*tmpuzd0);
        phi0d[i1][i0] = cff0*phi0d[i1][i0] + 2.0*dt*(tmpuzd*csq[i1][i0]+tmpuz*
            csqd[i1][i0]);
        phi0d0[i1][i0] = cff0*phi0d0[i1][i0] + 2.0*dt*(tmpuzd0*csq[i1][i0]+
            tmpuz*csqd0[i1][i0]);
        phi0[i1][i0] = phi0[i1][i0]*cff0 + tmpuz*2.0*dt*csq[i1][i0];
    }
    /* Homogeneous Dirichlet boundary conditions */
    if (lbc[1])
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            updd[s[1] - 2][i0] = -updd[s[1]+0][i0];
            upd[s[1] - 2][i0] = -upd[s[1]+0][i0];
            upd0[s[1] - 2][i0] = -upd0[s[1]+0][i0];
            up[s[1] - 2][i0] = -up[s[1]+0][i0];
            updd[s[1] - 3][i0] = -updd[s[1]+1][i0];
            upd[s[1] - 3][i0] = -upd[s[1]+1][i0];
            upd0[s[1] - 3][i0] = -upd0[s[1]+1][i0];
            up[s[1] - 3][i0] = -up[s[1]+1][i0];
            updd[s[1] - 4][i0] = -updd[s[1]+2][i0];
            upd[s[1] - 4][i0] = -upd[s[1]+2][i0];
            upd0[s[1] - 4][i0] = -upd0[s[1]+2][i0];
            up[s[1] - 4][i0] = -up[s[1]+2][i0];
        }
    if (rbc[1])
        for (i0 = s[0]; i0 < e[0]+1; ++i0) {
            updd[e[1] + 2][i0] = -updd[e[1]-0][i0];
            upd[e[1] + 2][i0] = -upd[e[1]-0][i0];
            upd0[e[1] + 2][i0] = -upd0[e[1]-0][i0];
            up[e[1] + 2][i0] = -up[e[1]-0][i0];
            updd[e[1] + 3][i0] = -updd[e[1]-1][i0];
            upd[e[1] + 3][i0] = -upd[e[1]-1][i0];
            upd0[e[1] + 3][i0] = -upd0[e[1]-1][i0];
            up[e[1] + 3][i0] = -up[e[1]-1][i0];
            updd[e[1] + 4][i0] = -updd[e[1]-2][i0];
            upd[e[1] + 4][i0] = -upd[e[1]-2][i0];
            upd0[e[1] + 4][i0] = -upd0[e[1]-2][i0];
            up[e[1] + 4][i0] = -up[e[1]-2][i0];
        }
    if (lbc[0])
        for (i1 = s[1]; i1 < e[1]+1; ++i1) {
            updd[i1][s[0] - 2] = -updd[i1][s[0]+0];
            upd[i1][s[0] - 2] = -upd[i1][s[0]+0];
            upd0[i1][s[0] - 2] = -upd0[i1][s[0]+0];
            up[i1][s[0] - 2] = -up[i1][s[0]+0];
            updd[i1][s[0] - 3] = -updd[i1][s[0]+1];
            upd[i1][s[0] - 3] = -upd[i1][s[0]+1];
            upd0[i1][s[0] - 3] = -upd0[i1][s[0]+1];
            up[i1][s[0] - 3] = -up[i1][s[0]+1];
            updd[i1][s[0] - 4] = -updd[i1][s[0]+2];
            upd[i1][s[0] - 4] = -upd[i1][s[0]+2];
            upd0[i1][s[0] - 4] = -upd0[i1][s[0]+2];
            up[i1][s[0] - 4] = -up[i1][s[0]+2];
        }
    if (rbc[0])
        for (i1 = s[1]; i1 < e[1]+1; ++i1) {
            updd[i1][e[0] + 2] = -updd[i1][e[0]-0];
            upd[i1][e[0] + 2] = -upd[i1][e[0]-0];
            upd0[i1][e[0] + 2] = -upd0[i1][e[0]-0];
            up[i1][e[0] + 2] = -up[i1][e[0]-0];
            updd[i1][e[0] + 3] = -updd[i1][e[0]-1];
            upd[i1][e[0] + 3] = -upd[i1][e[0]-1];
            upd0[i1][e[0] + 3] = -upd0[i1][e[0]-1];
            up[i1][e[0] + 3] = -up[i1][e[0]-1];
            updd[i1][e[0] + 4] = -updd[i1][e[0]-2];
            upd[i1][e[0] + 4] = -upd[i1][e[0]-2];
            upd0[i1][e[0] + 4] = -upd0[i1][e[0]-2];
            up[i1][e[0] + 4] = -up[i1][e[0]-2];
        }
}
