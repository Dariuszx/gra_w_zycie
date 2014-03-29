#include <gtk/gtk.h>
#include "gtk.h"
#include "bool.h"

struct graphics_gtk gui;
struct buttons_gtk przyciski;
struct boxes_gtk kontenery;

static gboolean zamkniecie_okna( GtkWidget *okno, GdkEvent *event, gpointer data ) {
    return FALSE;
}

static void destroy( GtkWidget *okno, gpointer data ) {
    gtk_main_quit ();
}

void stworz_okno( int *argc, char ***argv, int width, int height ) {
	
	GtkWidget* okno;

	gtk_init( argc, argv );
	gui.okno = gtk_window_new (GTK_WINDOW_TOPLEVEL); /* Tworzę okno */
	okno = gui.okno;

	gtk_window_set_title( GTK_WINDOW( okno ), "GRA" );
	gtk_window_set_default_size( GTK_WINDOW( okno ), (gint)width, (gint)height );
	gtk_window_set_position( GTK_WINDOW( okno ), GTK_WIN_POS_CENTER );
	g_signal_connect( okno, "delete-event", G_CALLBACK (zamkniecie_okna), NULL);
	g_signal_connect( okno, "destroy", G_CALLBACK (destroy), NULL);
	gtk_container_set_border_width (GTK_CONTAINER ( okno ), 20);
}


void dodaj_przycisk( BUTTON_GTK TYP, char* title ) {

	switch( TYP ) {
		case QUIT:
			przyciski.quit = gtk_button_new_with_label( title  );
			gtk_widget_set_size_request( przyciski.quit, 100, 100 );
			g_signal_connect_swapped( przyciski.quit, "clicked", G_CALLBACK(gtk_widget_destroy), gui.okno);
			gtk_widget_show( przyciski.quit );
		break;
		case START:
			przyciski.start = gtk_button_new_with_label( title  );
           	gtk_widget_set_size_request( przyciski.start, 100, 100 );
           	g_signal_connect_swapped( przyciski.start, "clicked", G_CALLBACK(gtk_widget_destroy), gui.okno);
           	gtk_widget_show( przyciski.start );
	}

}

void stworz_menu( ) {

    kontenery.menu_box = gtk_hbox_new( FALSE, 10 );
    dodaj_przycisk( START, "Start" );
    gtk_box_pack_start( GTK_BOX( kontenery.menu_box ), przyciski.start, TRUE, FALSE, 1 );
	dodaj_przycisk( QUIT, "Wyjście" );
	gtk_box_pack_start( GTK_BOX( kontenery.menu_box ), przyciski.quit, FALSE, FALSE, 1 );
	gtk_container_add( GTK_CONTAINER( gui.okno ), kontenery.menu_box );	
	gtk_widget_show( kontenery.menu_box );

}


void wyswietl_okno( ) { /* Wyświetlam okno */
	
	gtk_widget_show( gui.okno );

}



