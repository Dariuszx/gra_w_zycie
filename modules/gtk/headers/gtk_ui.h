#ifndef GTK_UI
	#define GTK_UI

	#include "graphics.h" /* ustawienia wyświetlania */
	#include "args.h"
	#include "mesh.h"
	#include "gtk.h"

	error gtk_ui( struct graphics_gtk*, struct graphics*, struct args*, struct mesh* );

#endif
