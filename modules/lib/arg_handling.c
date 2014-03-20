#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "args.h"
#include "error_handling.h"

error arg_handling( struct args* argumenty, int argc, char **argv ) {

	#ifdef DEBUG
		printf( "Wchodzę do modułu arg_handling\n" ); 
	#endif
	
	int opt;

	argumenty = malloc( sizeof *argumenty );
	if ( argumenty == NULL ) return MALLOC_ERROR;

	while( ( opt = getopt( argc, argv, "f:n:" ) ) != -1 ) {

		switch( opt ) {
			case 'f':
				if ( (argumenty->file_in = fopen( optarg, "r" )) == NULL ) {
					printf( "Nie udało się otworzyć pliku: %s.\n", optarg );
					return FOPEN_ERROR;
				}
			break;
			case 'n':
				if ( (argumenty->n = atoi( optarg )) <= 0 ) {
					printf( "Podano nieprawidłową licznę generacji -n.\n" );
					return OUT_OF_RANGE;
				}
			break;
		}
	}

	#ifdef DEBUG
		printf( "Wychodzę z modułu arg_handling\n" );
	#endif
	
	return FINE;
}
