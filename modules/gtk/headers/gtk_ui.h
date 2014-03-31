#ifndef GTK_UI
	#define GTK_UI

	#include "graphics.h" /* ustawienia wyświetlania */
	#include "args.h"
	#include "mesh.h"

	error gtk_ui( struct graphics*, struct args*, struct mesh*, int*, char*** );

#endif
