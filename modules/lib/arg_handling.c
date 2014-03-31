#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "args.h"
#include "error_handling.h"
#include "graphics.h"
#include "bool.h"

error arg_handling( struct args* argumenty, int argc, char **argv ) {

	int opt;

	#ifdef DEBUG
		message( "\n#Wchodzę do modułu arg_handling\n", GREEN ); 
	#endif

	argumenty->file_in = NULL;
	argumenty->file_out = NULL;
	argumenty->image_name = NULL;
	argumenty->rules = NULL;
	argumenty->n = N_DEFAULT;
	argumenty->k = K_DEFAULT;
	argumenty->x_resolution = X_RESOLUTION;
	argumenty->y_resolution = Y_RESOLUTION;
	argumenty->graphics_ui = false;

	while( ( opt = getopt( argc, argv, "f:n:k:r:o:i:x:y:g:" ) ) != -1 ) {
		switch( opt ) {
			case 'g': /* Otwieram program z interfejsem graficznym */
				argumenty->graphics_ui = true;
				break;
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
			case 'o':
				argumenty->file_out = optarg;
			   	#ifdef DEBUG
               		printf( "\tPodana nazwa pliku z danymi to: %s.\n", argumenty->file_out );
               	#endif
				break;
		   	case 'i':
               	argumenty->image_name = optarg;
				argumenty->image_folder = malloc( 128 * sizeof * argumenty->image_folder );
               	#ifdef DEBUG
               	    printf( "\tPodana nazwa folderu do przechowywania obrazów: %s.\n", argumenty->image_name );
               	#endif
               	break;
		 	case 'x':
              	#ifdef DEBUG
                   	printf( "\tPodana rozdzielczość obrazka x to: %s.\n", optarg );
            	#endif
         		if ( (argumenty->x_resolution = atoi( optarg )) <= 0 ) {
           			argumenty->x_resolution = X_RESOLUTION; /* jeżeli nie podano prawidłowej liczby przypisuję wartość domyślną */
                }
                break;
            case 'y':
               	#ifdef DEBUG
                   	printf( "\tPodana rozdzielczość obrazka y to: %s.\n", optarg );
               	#endif
               	if ( (argumenty->y_resolution = atoi( optarg )) <= 0 ) {
                   	argumenty->y_resolution = Y_RESOLUTION; /* jeżeli nie podano prawidłowej liczby przypisuję wartość domyślną */
             	}
               	break;
		}
	}
	
	if (argumenty->file_in == NULL ) argumenty->file_in = FILE_IN_DEFAULT;
	if (argumenty->file_out == NULL ) argumenty->file_out = FILE_OUT_DEFAULT;
	if (argumenty->rules == NULL ) argumenty->rules = RULES_DEFAULT;
    if (argumenty->image_name == NULL && argumenty->graphics_ui != true ) {
		printf( "*[-i]Nie podano nazwy katalogu w którym mają być zapisane obrazki.\n" );
        return ARG_ERROR;
    }



	#ifdef DEBUG
		message( "#Wychodzę z modułu arg_handling\n", GREEN );
	#endif
	
	return FINE;
}
