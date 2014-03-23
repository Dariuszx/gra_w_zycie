#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "mesh.h"
#include "rules.h"
#include "error_handling.h"
#include "data_saving.h"
#include "image_generation.h"
#include "cellular_automaton.h"

error cellular_automaton( struct mesh* siatka, struct args* argumenty ) {

	struct rules zasady;
	error status;
	
	#ifdef DEBUG
		printf( "Wchodzę do modułu cellular_automaton.\n" );
	#endif


	if( (status = select_rules( argumenty, &zasady )) != FINE ) return status;  


	#ifdef DEBUG
		printf( "Wychodzę z modułu cellular_automaton.\n" );
	#endif

	return FINE;
}
