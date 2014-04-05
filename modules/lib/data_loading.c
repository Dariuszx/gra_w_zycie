#include <stdio.h>
#include <stdlib.h>
#include "mesh.h"
#include "error_handling.h"
#include "graphics.h"
#include "program_log.h"

error data_loading( struct mesh* siatka, char* file_in ) {

	FILE* filein;
	int i,j,x,y;
	int c;
	error status;

	#ifdef DEBUG
		message( "\n#Wchodzę do modułu data_loading.\n", GREEN );
		printf( "\tOtwieram plik z danymi %s.\n", file_in );
	#endif
	
	if ( (filein = fopen( file_in, "r" )) == NULL ) {
		add_log( "#Nie mogę otworzyć pliku z danymi: %s.", file_in );
		return FOPEN_ERROR;
	}

	/* czytam pierwszą linie pliku zawierającą rozmiar siatki (x,y) */
	if ( fscanf( filein, "%d %d", &x, &y) != 2 ) {
		add_log( "#Błędny format danych wejściowych pliku: %s.", file_in );
		fclose( filein );
		return FORMAT_ERROR;
	}

	/* sprawdzam czy użytkownik nie podał zbyt dużych lub nieprawidłowych rozmiarów tablicy */
	if ( x > MAX_X || y > MAX_Y || x <= 0 || y <= 0 ) {
		add_log( "#W pliku wejściowym zdefiniowano nieakceptowalne rozmiary siatki." );
		fclose( filein );
		return OUT_OF_RANGE;
	}
	
	/* Tworzę siatkę */
	if( (status = make_mesh( siatka, x, y )) != FINE ) {
		fclose( filein );
		return status;	
	}
	
	/* Wczytuję dane */
	while ( (c = fscanf( filein, "%d %d", &x, &y )) == 2 ) {
		
		if( c == EOF ) break; /* jeżeli nie odczytano 2 poprawnych współrzędnych */
		else if( c != 2 ) continue; /* jeżeli napotkano koniec pliku */
		else if( x >= siatka->x || y >= siatka->y || x < 0 || y < 0 ) continue; /* jeżeli współrzędne nie mieszczą się w zakresie tablicy */
		else { /* wszystko OK (; */
			siatka->siatka[x][y] = 1;
		}
	}

	fclose( filein );

	#ifdef DEBUG
	if( siatka->x <= 64 && siatka->y <= 64 ) {
		printf( "\t" );
		for( j=0; j < siatka->y; j++ ) {
			for( i=0; i < siatka->x; i++ ) {
				if( siatka->siatka[i][j] == 1 )printf( "1 " );
				else printf( ". " );		
			}
			printf( "\n\t" );
		}
		printf( "\n" );
	}
		message( "#Wychodzę z modułu data_loading.\n", GREEN );
	#endif

	return FINE;
}
