#include <gtk/gtk.h>
#include "gtk.h"
#include "gtk_actions.h"
#include "bool.h"

struct gtk_graphics gui;
struct gtk_buttons przyciski;
struct gtk_boxes kontenery;
struct gtk_menu menu;

void gtk_make_window( int *argc, char ***argv, int width, int height ) {
	
	GtkWidget* okno;

	gtk_init( argc, argv );
	gui.okno = gtk_window_new (GTK_WINDOW_TOPLEVEL); /* Tworzę okno */
	okno = gui.okno;

	gtk_window_set_title( GTK_WINDOW( okno ), "GRA" );
	gtk_window_set_default_size( GTK_WINDOW( okno ), (gint)width, (gint)height );
	gtk_window_set_position( GTK_WINDOW( okno ), GTK_WIN_POS_CENTER );
	g_signal_connect( okno, "delete-event", G_CALLBACK (zamkniecie_okna), NULL);
	g_signal_connect( okno, "destroy", G_CALLBACK (destroy), NULL);
	gtk_container_set_border_width (GTK_CONTAINER ( okno ), 0);

	gtk_menu( &kontenery, &menu, &gui );

}

void gtk_show_window( ) { /* Wyświetlam okno */	
	gtk_widget_show( gui.okno );
}
