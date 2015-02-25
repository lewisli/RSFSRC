/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_error_h
#define _sf_error_h


void sf_error( const char *format, ... );
/*< Outputs an error message to stderr and terminates the program. 
---
Format and variable arguments follow printf convention. Additionally, a ':' at
the end of format adds system information for system errors. >*/


void sf_warning( const char *format, ... );
/*< Outputs a warning message to stderr. 
---
Format and variable arguments follow printf convention. Additionally, a ':' at
the end of format adds system information for system errors. >*/

#endif