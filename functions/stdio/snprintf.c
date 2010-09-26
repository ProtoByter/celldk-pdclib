/* $Id$ */

/* snprintf( char *, size_t, const char *, ... )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>
#include <stdarg.h>

#ifndef REGTEST

int snprintf( char * _PDCLIB_restrict s, size_t n, const char * _PDCLIB_restrict format, ...)
{
    int rc;
    va_list ap;
    va_start( ap, format );
    rc = vsnprintf( s, n, format, ap );
    va_end( ap );
    return rc;
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

#include <string.h>
#include <limits.h>

#define testprintf( s, n, format, ... ) snprintf( s, n, format, __VA_ARGS__ )

#define TESTCASE_SPRINTF( x ) if ( strcmp( buffer, x ) == 0 ) {} \
                              else { TEST_RESULTS += 1; printf( "FAILED: " __FILE__ ", line %d - \"%s\" != %s\n", __LINE__, buffer, #x ); }

int main( void )
{
    char buffer[100];
#include "printf_testcases.incl"
    return TEST_RESULTS;
}

#endif
