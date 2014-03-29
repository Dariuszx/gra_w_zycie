#ifndef GRAPHICS_GTK
	#define GRAPHICS_GTK
	
	#include <gtk/gtk.h>

	typedef enum { START, QUIT } BUTTON_GTK;

	struct graphics_gtk {
		GtkWidget* okno;
	};

	struct buttons_gtk {
		GtkWidget* quit;
		GtkWidget* start;
	};

	struct boxes_gtk {
		GtkWidget* menu_box;
	};

	void stworz_okno( int*, char***, int, int );
	void wyswietl_okno( );
	void dodaj_przycisk( BUTTON_GTK, char* );
	void stworz_menu( );

#endif
