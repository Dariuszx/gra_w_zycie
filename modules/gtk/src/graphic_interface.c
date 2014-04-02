#include "error_handling.h"
#include "mesh.h"
#include "args.h"
#include "graphics.h"
#include "gtk.h"
#include "bool.h"

error graphic_interface( struct graphics* settings, struct args* argumenty, struct mesh* siatka, int* argc, char*** argv ) {

	struct gtk_graphics gui;

	if( argumenty->graphics_ui != true ) return FINE; /* Uruchamiam program w tybie tekstowym */

	#ifdef DEBUG
		message( "#Wchodzę do modułu graphic_interface.\n", GREEN );
	#endif

	gtk_import_data( settings, argumenty, siatka );

	gtk_make_window( argc, argv, 800, 600 );	

	gtk_show_window( );
	gtk_main();

	#ifdef DEBUG
  		message( "#Wychodzę z modułu graphic_interface.\n", GREEN );
	#endif


	return GTK_FINE;
}
