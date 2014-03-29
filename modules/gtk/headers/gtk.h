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

	struct menu_gtk {
		GtkWidget* pasek;

		GtkWidget* menu_plik;
		GtkWidget* menu_pomoc;

		GtkWidget* plik;
			GtkWidget* zapisz;
			GtkWidget* wyjdz;

		GtkWidget* pomoc;
			GtkWidget* oprogramie;
	};

	void stworz_okno( int*, char***, int, int );
	void wyswietl_okno( );
	void dodaj_przycisk( BUTTON_GTK, char* );
	void stworz_menu( );

#endif
