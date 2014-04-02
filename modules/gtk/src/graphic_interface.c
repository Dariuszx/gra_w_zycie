#include "error_handling.h"
#include "mesh.h"
#include "args.h"
#include "graphics.h"
#include "gtk.h"
#include "bool.h"

error graphic_interface( struct graphics* settings, struct args* argumenty, struct mesh* siatka, int* argc, char*** argv ) {

	struct gtk_graphics gui;
	struct rules zasady;

	if( argumenty->graphics_ui != true ) return FINE; /* Uruchamiam program w tybie tekstowym */

	#ifdef DEBUG
		message( "#Wchodzę do modułu graphic_interface.\n", GREEN );
	#endif

	/* Przekazuje struktury do modułu gtk_ */
	gtk_import_data( settings, argumenty, siatka, &zasady );

	/* Tworzę okno */
	gtk_make_window( argc, argv, 800, 600 );	
	gtk_make_header( );

	/* Wyświetlam okno */
	gtk_show_window( );

	gtk_main(); /* Pętla główna */

	#ifdef DEBUG
  		message( "#Wychodzę z modułu graphic_interface.\n", GREEN );
	#endif


	return GTK_FINE;
}
