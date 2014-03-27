#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "args.h"
#include "mesh.h"
#include "rules.h"
#include "error_handling.h"

/* Funkcja ma za zadanie wczytywanie zasad przekształceń generacji */
error select_rules( struct args* argumenty, struct rules* zasady ) {

	FILE *file_rules;
	int cell_status; /* żywa lub martwa, 0/1 */
	int elements; /* liczba zasad dla dla komórki żywej/martwej */
	int i;
	int *temp;

	zasady->living_cell = NULL;
	zasady->dead_cell = NULL;

	#ifdef DEBUG
		message("\t#Wczytuję plik z zasadami generacji.\n", GREEN );
	#endif

	if( (file_rules = fopen( argumenty->rules, "r" )) == NULL ) {
		printf( "*Nie udało się otworzyć pliku z zasadami generacji: %s.\n", argumenty->rules );
		return FOPEN_ERROR;
	}

	while( 1 ) {	
		if( fscanf( file_rules, "%d %d", &cell_status, &elements ) != 2 ) {
			printf( "*Niepoprawny format danych wejściowych pliku z zasadami (1): %s.\n", argumenty->rules );
			return FORMAT_ERROR;
		}

		if( (cell_status != 1 && cell_status != 0) || elements < 0 ) {
			printf( "*Niepoprawny format danych wejściowych pliku z zasadami (2): %s.\n", argumenty->rules );
			return FORMAT_ERROR;
		}
	
		if( cell_status == 1 ) {
			if( zasady->living_cell != NULL ) break;
			if ( (zasady->living_cell = calloc( elements, sizeof * zasady->living_cell )) == NULL ) return MALLOC_ERROR;
			zasady->living_elements = elements;
			temp = zasady->living_cell;
		} else if( cell_status == 0 ) {
			if( zasady->dead_cell != NULL ) break;
            if ( (zasady->dead_cell = calloc( elements, sizeof * zasady->dead_cell )) == NULL ) return MALLOC_ERROR;
            zasady->dead_elements = elements;
			temp = zasady->dead_cell;
		}

		for( i=0; i<elements; i++ ) {
			if( ( fscanf( file_rules, "%d", &temp[i] ) != 1) || temp[i] > 8 || temp[i] < 0 ) {
				printf( "*Niepoprawny format danych wejściowych pliku z zasadami (3): %s.\n", argumenty->rules );
				return FORMAT_ERROR;
			}  
		}
		if( zasady->dead_cell != NULL && zasady->living_cell != NULL ) break;
	}

	#ifdef DEBUG
		printf( "\t\tIlość sąsiadów żywych dla komórki żywej, aby komórka pozostała żywa: " );
		for( i=0; i<zasady->living_elements; i++ )
			printf( "%s%d%s ", COLOR_RED, zasady->living_cell[i], COLOR_RESET );

		printf( "\n\t\tIlość sądiadów żywych dla komórki martwej, aby komórka stała się żywa: " );
		for( i=0; i<zasady->dead_elements; i++ )
			printf( "%s%d%s ", COLOR_RED, zasady->dead_cell[i], COLOR_RESET );

		printf( "\n" );
	#endif
	
	return FINE;
}
