#include <stdlib.h>
#include "error_handling.h"
#include "mesh.h"
#include "rules.h"
#include "program_log.h"

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

void free_log( struct program_log* program_logi ) {

	int i;

	for( i=0; i < program_logi->size; i++ ) {
		free( program_logi->log[i] );
	}

	free( program_logi->log );
}
