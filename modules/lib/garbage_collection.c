#include <stdlib.h>
#include "error_handling.h"
#include "mesh.h"
#include "rules.h"

void free_mesh( struct mesh* siatka ) {

	int i;

	for( i=0; i < siatka->x; i++ ) {
		free( siatka->siatka[i] );
	}
	free( siatka->siatka );
}

void free_rules( struct rules* zasady ) {

	free( zasady->living_cell );
	free( zasady->dead_cell );
}
