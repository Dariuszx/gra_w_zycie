#include <gtk/gtk.h>
#include "gtk.h"
#include "bool.h"

struct graphics_gtk gui;
struct buttons_gtk przyciski;

static gboolean zamkniecie_okna( GtkWidget *okno, GdkEvent *event, gpointer data ) {
    return FALSE;
}

static void destroy( GtkWidget *okno, gpointer data ) {
    gtk_main_quit ();
}

void stworz_okno( int *argc, char ***argv ) {
	
	gtk_init( argc, argv );
	gui.okno = gtk_window_new (GTK_WINDOW_TOPLEVEL); /* Tworzę okno */
	g_signal_connect( gui.okno, "delete-event", G_CALLBACK (zamkniecie_okna), NULL);
	g_signal_connect( gui.okno, "destroy", G_CALLBACK (destroy), NULL);
	gtk_container_set_border_width (GTK_CONTAINER ( gui.okno ), 20);
}	

void dodaj_przycisk( BUTTON_GTK TYP, char* title ) {

	GtkWidget* button;
	bool status = false;

	switch( TYP ) {
		case QUIT:
			status = true;
			button = przyciski.quit; 
			button = gtk_button_new_with_label( title  );
			g_signal_connect_swapped( button, "clicked", G_CALLBACK(gtk_widget_destroy), gui.okno);
		break;
	}

	if( status == true ) {
		gtk_container_add( GTK_CONTAINER( gui.okno ), button );
		gtk_widget_show( button );
	}
}

void wyswietl_okno( ) { /* Wyświetlam okno */
	
	gtk_widget_show( gui.okno );

}



