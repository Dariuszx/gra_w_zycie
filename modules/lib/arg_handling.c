#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "args.h"
#include "error_handling.h"

error arg_handling( struct args* argumenty, int argc, char **argv ) {

	int opt;

	#ifdef DEBUG
		printf( "\nWchodzę do modułu arg_handling\n" ); 
	#endif

	argumenty->file_in = NULL;
	argumenty->file_out = NULL;
	argumenty->image_name = NULL;
	argumenty->rules = NULL;

	while( ( opt = getopt( argc, argv, "f:n:k:r:" ) ) != -1 ) {
		switch( opt ) {
			case 'f':
				argumenty->file_in = optarg;
				#ifdef DEBUG
					printf( "\tPodana nazwa pliku z danymi to: %s.\n", argumenty->file_in );
				#endif
				break;
			case 'n':
				#ifdef DEBUG
					printf( "\tPodana liczba generacji to: %s.\n", optarg );
				#endif
				if ( (argumenty->n = atoi( optarg )) <= 0 ) {
					argumenty->n = N_DEFAULT; /* jeżeli podano nieprawidłową liczbe przypisuję wartość domyślną */
				}
				break;
			case 'k':
				#ifdef DEBUG
					printf( "\tPodana liczba generowanych obrazków to: %s.\n", optarg );
				#endif
				if ( (argumenty->k = atoi( optarg )) <= 0 ) {
					argumenty->k = K_DEFAULT; /* jeżeli nie podano prawidłowej liczby przypisuję wartość domyślną */
				}
				break;
			case 'r':
				argumenty->rules = optarg;
			   	#ifdef DEBUG
             		printf( "\tPodany plik z zasadami to: %s.\n", argumenty->rules );
               	#endif
				break;
		}
	}
	
	if (argumenty->file_in == NULL ) argumenty->file_in = FILE_IN_DEFAULT;
	if (argumenty->file_out == NULL ) argumenty->file_out = FILE_OUT_DEFAULT;
	if (argumenty->image_name == NULL ) argumenty->image_name = IMAGE_NAME_DEFAULT;
	if (argumenty->rules == NULL ) argumenty->rules = RULES_DEFAULT;

	#ifdef DEBUG
		printf( "Wychodzę z modułu arg_handling\n" );
	#endif
	
	return FINE;
}
