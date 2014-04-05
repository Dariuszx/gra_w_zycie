#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "mesh.h"
#include "arg_handling.h"
#include "error_handling.h"
#include "data_loading.h"
#include "cellular_automaton.h"
#include "bool.h"
#include "graphics.h"
#include "garbage_collection.h"
#include "program_log.h"

    char *about_1 =  "Usage: gra_w_zycie [options]\n"
                        "\t Opcje wczytywania/zapisywania danych:\n"
                            "\t\t -f \t\tNazwa pliku z współrzędnymi siatki\n"
                            "\t\t -o \t\tNazwa pliku do którego będzie zapisana wynikowa siatko po n generacjach\n"
                            "\t\t -r \t\tNazwa pliku z zasadami tworzenia nowych generacji\n"
                            "\t\t -i \t\tNazwa katalogu do którego będą zapisane wygenerowane obrazki\n";
                        
	char *about_2 = 
					"\t Opcje generacji:\n"
                    	"\t\t -n \t\tIlość przeprowadzonych generacji na zadanej siatce\n"
                       	"\t\t -k \t\tIlość obrazków do wygenerowania\n"
                  	"\t Opcje wyświetlania:\n"
                       	"\t\t -x \t\tSzerokość w pixelach wygenerowanego obrazka\n"
                       	"\t\t -y \t\tWysokość w pixelach wygenerowanego obrazka\n"
                  	"\n\tWygenerowne pliki znajdują się w katalogu data/\n"
                   	"\tInformacje o działaniu programu znajdują się w /data/program.log\n\n";


int main( int argc, char **argv ) {

	bool wczytaj_modul = true; /* ustawiam zmienną na true, zezwalając na wywoływanie modułów */
	int modul_id = 0; /* rozpoczynam łądowanie modułów od identyfikatora modułu 0, dzięki numerowaniu modułów mogę łatwo określić kolejność wywoływania */
	error error_code = FINE;
   
   	struct graphics screen_settings; /* ustawienia graficzne */ 
	struct args argumenty; /* tutaj przechowuję argumenty wywołane przez użytkownika */
	struct mesh siatka; /* struktura siatki */;

	if ( initialize_log( 32 ) != FINE ) return MALLOC_ERROR; /* Tworzę strukturę do przechowywania logów z programu */

	/* W tym miejscu wczytuję kolejno moduły */
	while( wczytaj_modul == true ) {
		switch( modul_id ) { /*ustalono skok wartości co 5, tak aby można było dodawać nowe moduły w odpowiedniej kolejności */
			case 0:
				error_code = arg_handling( &argumenty, argc, argv ); /* ładuję moduł arg_handling */ 	
				break;
			case 5:
				error_code = data_loading( &siatka, argumenty.file_in ); /* ładuję moduł data_loading, czyli wczytuję dane z pliku */	
				break;
			case 8:
				error_code = set_graphics_settings( &screen_settings, &siatka, &argumenty );
				break;
			case 10:
				error_code = cellular_automaton( &siatka, &argumenty, &screen_settings );	
				break;
			case 15: /* jeżeli zmienna modul_id przekroczy jakąś wartość wychodzę z funkcji ładującej moduły */
				wczytaj_modul = false;
				break;
		}
		if ( error_handling( error_code ) ) {
			printf( "%s%s", about_1, about_2 );
			break; /* krytyczny błąd, zamykam program */
		}
		modul_id++;  
	}

	write_log( );
	free_log( &logi );
	if( siatka.siatka != NULL ) free_mesh( &siatka );

	return 0;
}
