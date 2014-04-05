#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "args.h"
#include "error_handling.h"
#include "graphics.h"
#include "program_log.h"


error arg_handling( struct args* argumenty, int argc, char **argv ) {

	int opt;

	#ifdef DEBUG
		message( "\n#Wchodzę do modułu arg_handling\n", GREEN ); 
	#endif

	argumenty->file_in = FILE_IN_DEFAULT;
	argumenty->file_out = FILE_OUT_DEFAULT;
	argumenty->image_name = NULL;
	argumenty->rules = RULES_DEFAULT;
	argumenty->n = N_DEFAULT;
	argumenty->k = K_DEFAULT;
	argumenty->x_resolution = X_RESOLUTION;
	argumenty->y_resolution = Y_RESOLUTION;

	while( ( opt = getopt( argc, argv, "f:n:k:r:o:i:x:y:" ) ) != -1 ) {
		switch( opt ) {
			case 'f':
				argumenty->file_in = optarg;

				#ifdef DEBUG
               		printf( "\tPodany plik z danymi to: %s.\n", argumenty->rules );
             	#endif
				break;
			case 'n':
				argumenty->n = atoi( optarg );
				
				#ifdef DEBUG
                	printf( "\tPodano liczbę generacji -n: %s.\n", argumenty->n );
               	#endif

				if ( (argumenty->n <= 0) || argumenty->n > MAX_N ) {
					add_log( "#Podano za dużą wartość -n[wartość] | Przypisuję N_DEFAULT=%d", N_DEFAULT );
					argumenty->n = N_DEFAULT; /* jeżeli podano nieprawidłową liczbe przypisuję wartość domyślną */
				}
				break;
			case 'k':
				argumenty->k = atoi( optarg );
			
				#ifdef DEBUG
                	printf( "\tPodano liczbę generowanych obrazków -k: %s.\n", argumenty->k );
               	#endif
			
				if ( (argumenty->k <= 0) || argumenty->n > MAX_K ) {
					add_log( "#Podano za dużą wartość -k[wartość] | Przypisuję K_DEFAULT=%d", K_DEFAULT );
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
				#ifdef DEBUG
               	    printf( "\tPodana nazwa folderu do przechowywania obrazów: %s.\n", argumenty->image_name );
               	#endif
               	break;
		 	case 'x':
              	#ifdef DEBUG
                   	printf( "\tPodana rozdzielczość obrazka x to: %s.\n", optarg );
            	#endif
				argumenty->x_resolution = atoi( optarg );
         		if ( (argumenty->x_resolution <= 0) || argumenty->x_resolution > MAX_X_RES ) {
           			add_log( "Podano zbyt dużą rozdzielczość -x[wartość] | Przypisuję X_DEFAULT=%d", MAX_X_RES );
					argumenty->x_resolution = X_RESOLUTION; /* jeżeli nie podano prawidłowej liczby przypisuję wartość domyślną */
                }
                break;
            case 'y':
               	#ifdef DEBUG
                   	printf( "\tPodana rozdzielczość obrazka y to: %s.\n", optarg );
               	#endif
				argumenty->y_resolution = atoi( optarg );
               	if ( (argumenty->y_resolution <= 0) || argumenty->y_resolution > MAX_Y_RES ) {
					add_log( "Podano zbyt dużą rozdzielczość -y[wartość] | Przypisuję Y_DEFAULT=%d", MAX_Y_RES );
                   	argumenty->y_resolution = Y_RESOLUTION; /* jeżeli nie podano prawidłowej liczby przypisuję wartość domyślną */
             	}
               	break;
		}
	}
	
	/* Dodaję logi */	
	add_log( "file_in = %s", argumenty->file_in );
	add_log( "file_out = %s", argumenty->file_out );
	add_log( "image_name = %s", argumenty->image_name );
	add_log( "rules = %s", argumenty->rules );
	add_log( "n = %d", argumenty->n );
	add_log( "k = %d", argumenty->k );
	add_log( "x_resolution = %d", argumenty->x_resolution );
	add_log( "y_resolution = %d", argumenty->y_resolution );


    if (argumenty->image_name == NULL ) {
		add_log( "#Nie podano nazwy katalogu w którym mają być zapisane obrazki -i[nazwa_katalogu].\n" );
        return ARG_ERROR;
    }

	#ifdef DEBUG
		message( "#Wychodzę z modułu arg_handling\n", GREEN );
	#endif
	
	return FINE;
}
