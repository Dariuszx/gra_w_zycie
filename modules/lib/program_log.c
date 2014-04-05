#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "program_log.h"
#include "error_handling.h"

error initialize_log( int size ) {

	int i;
	logi.size = size;
	logi.possition = 0;

	if( (logi.log = malloc( logi.size * sizeof * logi.log )) == NULL ) return MALLOC_ERROR;

	for( i=0; i < logi.size; i++ )
		if( (logi.log[i] = malloc( 128 * sizeof *logi.log[i] )) == NULL ) return MALLOC_ERROR;


	return FINE;
}

void add_log( char* message, ... ) {

	va_list args;
	char* result;

	if( logi.possition == (logi.size - 1) ) 
		if( resize_array_log( ) != FINE )
			;

    va_start( args, message );
    	vsprintf( logi.log[ logi.possition++ ], message, args );
    va_end( args );
/*
	strcpy( logi.log[ ++logi.possition ], result );
*/
}


error resize_array_log( ) {

	int i;
	logi.size *= 2;
	if( realloc( logi.log, logi.size ) != NULL ) return MALLOC_ERROR;

	for( i=(logi.size/2); i < logi.size; i++ )
		if( (logi.log[i] = malloc( 128 * sizeof *logi.log[i] )) == NULL ) return MALLOC_ERROR;

	return FINE;
}


error write_log( ) {


}
