#ifndef GRAPHICS_GTK
	#define GRAPHICS_GTK
	
	#include <gtk/gtk.h>
	#include "graphics.h"
	#include "args.h"
	#include "mesh.h"
	#include "rules.h"

	struct graphics* gtk_graphic_settings;
	struct args* gtk_args;
	struct mesh* gtk_siatka;
	struct rules* gtk_rules;

	struct gtk_graphics gui;
	struct gtk_buttons przyciski;
	struct gtk_boxes kontenery;
	struct gtk_menu menu;
	struct gtk_text tekst;

	typedef enum { START, QUIT } BUTTON_GTK;

	struct gtk_graphics {
		GtkWidget* okno;
	};

	struct gtk_buttons {
		GtkWidget* zapisz;
		GtkWidget* num2;
		GtkWidget* quit;
	};

	struct gtk_boxes {
		GtkWidget* main_box; /* Kontener główny */
		GtkWidget* menu_box; /* Pasek menu */
		GtkWidget* header_box;
		GtkWidget* table_properties;
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

	struct gtk_text {
		GtkWidget* naglowek;
	};

	void gtk_make_header( );
	void gtk_import_data( struct graphics*, struct args*, struct mesh*, struct rules* );
	void gtk_menu( struct gtk_boxes*, struct gtk_menu*, struct gtk_graphics* );
	void gtk_make_window( int*, char***, int, int );
	void gtk_show_window( );
	void dodaj_przycisk( BUTTON_GTK, char* );
	void stworz_menu( );

#endif
