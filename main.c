#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "mesh.h"
#include "arg_handling.h"
#include "error_handling.h"
#include "data_loading.h"
#include "cellular_automaton.h"
#include "bool.h"


int main( int argc, char **argv ) {

	bool wczytaj_modul = true; /* ustawiam zmienną na true, zezwalając na wywoływanie modułów */
	int modul_id = 0; /* rozpoczynam łądowanie modułów od identyfikatora modułu 0, dzięki numerowaniu modułów mogę łatwo określić kolejność wywoływania */
	error error_code = FINE;
    
	struct args argumenty; /* tutaj przechowuję argumenty wywołane przez użytkownika */
    struct mesh siatka; /* struktura siatki */;

	/* W tym miejscu wczytuję kolejno moduły */
	while( wczytaj_modul == true ) {
		switch( modul_id ) { /* ustalono skok wartości co 5, tak aby można było dodawać nowe moduły w odpowiedniej kolejności */
			case 0:
				error_code = arg_handling( &argumenty, argc, argv ); /* ładuję moduł arg_handling */ 	
				break;
			case 5:
				error_code = data_loading( &siatka, argumenty.file_in ); /* ładuję moduł data_loading, czyli wczytuję dane z pliku */	
				break;
			case 10:
			
				break;
			case 15:

				break;	
			case 16: /* jeżeli zmienna modul_id przekroczy jakąś wartość wychodzę z funkcji ładującej moduły */
				wczytaj_modul = false;
				break;
			default:				
				break;
		}
		if ( error_handling( error_code ) ) return 1; /* krytyczny błąd, zamykam program */
		modul_id++;  
	}
	return 0;
}
