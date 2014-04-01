#ifndef GRAPHICS_GTK
	#define GRAPHICS_GTK
	
	#include <gtk/gtk.h>

	typedef enum { START, QUIT } BUTTON_GTK;

	struct gtk_graphics {
		GtkWidget* okno;
	};

	struct gtk_buttons {
		GtkWidget* quit;
		GtkWidget* start;
	};

	struct gtk_boxes {
		GtkWidget* menu_box;
	};

	struct gtk_menu {
		GtkWidget* pasek;

		GtkWidget* menu_plik;
		GtkWidget* menu_dane;
		GtkWidget* menu_pomoc;

		GtkWidget* plik;
			GtkWidget* zapisz;
			GtkWidget* wyjdz;

		GtkWidget* dane;
			GtkWidget* otworz_siatke;
			GtkWidget* otworz_zasady;

		GtkWidget* pomoc;
			GtkWidget* oprogramie;
	};

	void gtk_menu( struct gtk_boxes*, struct gtk_menu*, struct gtk_graphics* );
	void gtk_make_window( int*, char***, int, int );
	void gtk_show_window( );
	void dodaj_przycisk( BUTTON_GTK, char* );
	void stworz_menu( );

#endif
