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
	struct mesh siatka_tmp;
	error status;
	int i;
	double dk_count = (double)argumenty->n / argumenty->k; /* odstęp pomiędzy kolejnymi generacjami, gdzie miałbym tworzyć obrazy siatki */
	int ik_count = 1; /* tutaj zliczam ile obrazków wygenerowałem */


	#ifdef DEBUG
		printf( "Wchodzę do modułu cellular_automaton.\n" );
	#endif

	/* Wybieram zasady przejścia */
	if( ( status = select_rules( argumenty, &zasady )) != FINE ) return status;  

	/* kopiuję siatkę */
	if( (status = copy_mesh( siatka, &siatka_tmp )) != FINE ) return status;

	/* Tworzę folder przechowujący obrazki */
	if( (status = make_dir( argumenty->image_name, argumenty->image_folder )) != FINE ) return status;
	
	/* Tutaj przeprowadzam 'argumenty->n' kolejnych generacji */
	for( i=0; i < argumenty->n; i++ ) {
		if( (status = formation_generation( &siatka_tmp, &zasady )) != FINE ) return status; 
			/* sprawdzam czy z aktualnej generacji muszę stworzyć obrazek */
			if( (i+1) >= ik_count * dk_count || i == 0 ) { 
				/* tworzę obrazek */
				if( (status = generate_ppm( &siatka_tmp, argumenty->image_folder, ik_count )) != FINE ) return status;
				ik_count++; /* zwiększam licznik ilości obrazków */
			}	
	}

	/* Zapisuję osatnią wygenerowaną siatkę do pliku */
	if( (status = data_saving( &siatka_tmp, argumenty->file_out )) != FINE ) return status; 

	#ifdef DEBUG
		printf( "Wychodzę z modułu cellular_automaton.\n" );
	#endif

	return FINE;
}
