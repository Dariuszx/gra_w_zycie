#ifndef GRAPHICS_GTK
	#define GRAPHICS_GTK
	
	#include <gtk/gtk.h>

	typedef enum { QUIT } BUTTON_GTK;

	struct graphics_gtk {
		GtkWidget* okno;
	};

	struct buttons_gtk {
		GtkWidget* quit;
	};

	void stworz_okno( int*, char*** );
	void wyswietl_okno( );
	void dodaj_przycisk( BUTTON_GTK, char* );

#endif
