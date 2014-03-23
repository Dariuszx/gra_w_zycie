#include <stdio.h>
#include <stdlib.h>
#include "args.h" /* argumenty */
#include "mesh.h" /* siatka */
#include "rules.h" /* zasady ewolucji */
#include "error_handling.h" /* obsługa błędów */
#include "data_saving.h" /* zapisywanie generacji do pliku */
#include "image_generation.h" /* tworzenie obrazków */
#include "cellular_automaton.h"

/* Główna funkcja odpowiadająca za generowanie kolejnych generacji komórek */
error cellular_automaton( struct mesh* siatka, struct args* argumenty ) {

	struct rules zasady;
	error status;
	
	#ifdef DEBUG
		printf( "Wchodzę do modułu cellular_automaton.\n" );
	#endif

	/* Wybieram zasady przejścia */
	if( ( status = select_rules( argumenty, &zasady )) != FINE ) return status;  


	#ifdef DEBUG
		printf( "Wychodzę z modułu cellular_automaton.\n" );
	#endif

	return FINE;
}
