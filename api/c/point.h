/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_point_h
#define _sf_point_h


#include "file.h"


#define DST2d(A,B) ( (B.x-A.x)*(B.x-A.x) + \
                     (B.z-A.z)*(B.z-A.z) ) 
#define DST3d(A,B) ( (B.x-A.x)*(B.x-A.x) + \
                     (B.y-A.y)*(B.y-A.y) + \
                     (B.z-A.z)*(B.z-A.z) ) 


#define JAC2d(O,A,B) ( (A.x-O.x)*(B.z-O.z)-(B.x-O.x)*(A.z-O.z) )


typedef struct{
    double x,z;   /* location */
    float  v;     /* value    */
}pt2d;


typedef struct{
    double x,y,z; /* location */
    float  v;     /* value    */
}pt3d;


void printpt2d(pt2d P);
/*< print point2d info  >*/


void printpt3d(pt3d P);
/*< print point3d info  >*/


void pt2dwrite1(sf_file F, 
		pt2d   *v, 
		size_t  n1, 
		int     k);
/*< output point2d 1-D vector >*/


void pt2dwrite2(sf_file F, 
		pt2d  **v, 
		size_t  n1, 
		size_t  n2,
		int     k);
/*< output point2d 2-D vector >*/


void pt3dwrite1(sf_file F, 
		pt3d   *v, 
		size_t  n1, 
		int     k);
/*< output point3d 1-D vector >*/


void pt3dwrite2(sf_file F, 
		pt3d  **v, 
		size_t  n1, 
		size_t  n2,
		int     k);
/*< output point3d 2-D vector >*/


void pt2dread1(sf_file F, 
	       pt2d   *v, 
	       size_t  n1, 
	       int     k);
/*< input point2d 1-D vector >*/


void pt2dread2(sf_file F, 
	       pt2d  **v, 
	       size_t  n1,
	       size_t  n2,
	       int     k);
/*< input point2d 2-D vector >*/


void pt3dread1(sf_file F, 
	       pt3d   *v, 
	       size_t  n1, 
	       int     k);
/*< input point3d 1-D vector >*/


void pt3dread2(sf_file F, 
	       pt3d  **v, 
	       size_t  n1, 
	       size_t  n2,
	       int     k);
/*< input point3d 2-D vector >*/


pt2d* pt2dalloc1( size_t n1);
/*< alloc point2d 1-D vector >*/


void pt2dfree1 (pt2d* tofree);
/*< free allocated storage >*/


pt2d** pt2dalloc2( size_t n1, size_t n2);
/*< alloc point2d 2-D vector >*/


pt2d*** pt2dalloc3( size_t n1,
		    size_t n2,
		    size_t n3);
/*< alloc point2d 3-D vector >*/


pt3d* pt3dalloc1( size_t n1);
/*< alloc point3d 1-D vector >*/


pt3d** pt3dalloc2( size_t n1,
		   size_t n2);
/*< alloc point3d 2-D vector >*/


pt3d*** pt3dalloc3( size_t n1,
		    size_t n2,
		    size_t n3);
/*< alloc point3d 3-D vector >*/

#endif
