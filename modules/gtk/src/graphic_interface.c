#include "error_handling.h"
#include "mesh.h"
#include "args.h"
#include "graphics.h"
#include "gtk.h"

error graphic_interface( struct graphics* settings, struct args* argumenty, struct mesh* siatka, int* argc, char*** argv ) {

	struct graphics_gtk gui;

	stworz_okno( argc, argv, 800, 600 );
	stworz_menu( );
	wyswietl_okno( );

	gtk_main();

	return GTK_FINE;
}
