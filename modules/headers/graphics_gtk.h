#ifndef GRAPHICS_GTK
	#define GRAPHICS_GTK
	
	#include <gtk/gtk.h>

	struct graphics_gtk {
		GtkWidget* okno;
	};

	void stworz_okno( struct graphics_gtk*, int*, char*** );
	void wyswietl_okno( GtkWidget* );

#endif
