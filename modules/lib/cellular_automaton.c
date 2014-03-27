#include <stdio.h>
#include <stdlib.h>
#include "args.h" /* argumenty */
#include "mesh.h" /* siatka */
#include "rules.h" /* zasady ewolucji */
#include "graphics.h"
#include "error_handling.h" /* obsługa błędów */
#include "data_saving.h" /* zapisywanie generacji do pliku */
#include "image_generation.h" /* tworzenie obrazków */
#include "cellular_automaton.h"


/* Główna funkcja odpowiadająca za generowanie kolejnych generacji komórek */
error cellular_automaton( struct mesh* siatka, struct args* argumenty, struct graphics* screen_settings ) {

	struct rules zasady;	
	struct mesh siatka_tmp;
	error status;
	int i;
	double dk_count = (double)argumenty->n / argumenty->k; /* odstęp pomiędzy kolejnymi generacjami, gdzie miałbym tworzyć obrazy siatki */
	int ik_count = 1; /* tutaj zliczam ile obrazków wygenerowałem */


	#ifdef DEBUG
		message( "\n#Wchodzę do modułu cellular_automaton.\n", GREEN );
	#endif

	/* Wybieram zasady przejścia */
	if( ( status = select_rules( argumenty, &zasady )) != FINE ) return status;  

	/* kopiuję siatkę */
	if( (status = copy_mesh( siatka, &siatka_tmp )) != FINE ) return status;

	/* Tworzę folder przechowujący obrazki */
	if( (status = make_dir( argumenty->image_name, argumenty->image_folder )) != FINE ) return status;
	
	/* Tutaj przeprowadzam 'argumenty->n' kolejnych generacji */
	for( i=0; i < argumenty->n; i++ ) {
			
		/* sprawdzam czy z aktualnej generacji muszę stworzyć obrazek */
		if( (i+1) >= ik_count * dk_count || i == 0 ) { 
			
			/* Tworzę obrazek */ 
			if( (status = generate_image( &siatka_tmp, screen_settings, argumenty->image_folder, ik_count )) != FINE ) return status;
			ik_count++; /* zwiększam licznik ilości obrazków */
		}	

		/* Tworzę kolejną generację. */
        if( (status = formation_generation( &siatka_tmp, &zasady )) != FINE ) return status;

	}

	/* Zapisuję osatnią wygenerowaną siatkę do pliku */
	if( (status = data_saving( &siatka_tmp, argumenty->file_out )) != FINE ) return status; 

	#ifdef DEBUG
		message( "\n#Wychodzę z modułu cellular_automaton.\n", GREEN );
	#endif

	return FINE;
}
