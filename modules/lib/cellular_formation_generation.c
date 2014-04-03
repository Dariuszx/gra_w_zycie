#include <stdio.h>
#include <stdlib.h>
#include "mesh.h"
#include "rules.h"
#include "error_handling.h"
#include "garbage_collection.h"

/* Określam z iloma żywmi komórkami graniczy dana komórka */
int neighborhood( struct mesh* siatka, int x, int y ) {

	int living_count = 0;
	int x1, y1;

	for( y1=-1; y1 <= 1; y1++ ) {
		for( x1=-1; x1 <= 1; x1++ ) {
			if( x+x1 >= 0 && y+y1 >= 0 && x+x1 < siatka->x && y+y1 < siatka->y && ( x1 != 0 || y1 != 0 ) ) {
				living_count += siatka->siatka[x+x1][y+y1];
			}		
		}
	} 
	return living_count; /* zwracam liczbę żywych sąsiadów */
}

/* Na podstawie zasad przekształcam konkretną komórkę na żywą/martwą */
int generate( int cell, int neighbors, struct rules *zasady ) {

	int i;	

	if( cell == 0 ) {
		for( i=0; i < zasady->dead_elements; i++ )
			if( zasady->dead_cell[i] == neighbors ) return 1;
	} else if( cell == 1 ) {
		for( i=0; i < zasady->living_elements; i++ )
			if( zasady->living_cell[i] == neighbors ) return 1;
	}

	return 0; /* komórka nie spełnia zasad, staje się martwa */
}

/* Główna funkcja decydująca czy komórka staje się żywa czy martwa */
error formation_generation( struct mesh* siatka, struct rules* zasady ) {

	struct mesh siatka_tmp; /* na podstawie siatki pierwotnej 'siatka_tmp' będe zapisywał kolejną generację do 'siatka'  */
	int x,y;
	error status;

	/* kopiuję siatkę do zmiennej tymczasowej */
	if( (status = copy_mesh( siatka, &siatka_tmp )) != FINE ) return status; 

	/* przeprowadzam generację */
	for( y=0; y < siatka->y; y++ ) {
		for( x=0; x < siatka->x; x++ ) {
				siatka->siatka[x][y] = generate( siatka_tmp.siatka[x][y], neighborhood( &siatka_tmp, x, y ), zasady );
		}
	}

	free_mesh( &siatka_tmp );
	
	return FINE;
}
