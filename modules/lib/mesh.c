#include <stdlib.h>
#include "error_handling.h"
#include "mesh.h"

error make_mesh( struct mesh* siatka, int x, int y ) {

	int j;
	
	siatka->x = x;
	siatka->y = y;	

    if( ( siatka->siatka = malloc( siatka->x * sizeof *siatka->siatka ) ) == NULL ) return MALLOC_ERROR;

    for( j=0; j < siatka->x; j++ )
        if( ( siatka->siatka[j] = calloc( siatka->y, sizeof *siatka->siatka[j] ) ) == NULL ) return MALLOC_ERROR;

	return FINE;
}

error copy_mesh( struct mesh* a, struct mesh* b ) {

	error status;
	int x,y;

	if( (status = make_mesh( b, a->x, a->y ) ) != FINE ) return status;

	for( y=0; y < a->y; y++ )
		for( x=0; x < a->x; x++ )
			b->siatka[x][y] = a->siatka[x][y];

	return FINE;
}
