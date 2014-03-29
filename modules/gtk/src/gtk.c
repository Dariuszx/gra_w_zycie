#include <gtk/gtk.h>
#include "error_handling.h"
#include "gtk.h"

void stworz_okno( struct graphics_gtk* s, int *argc, char ***argv ) {
	
	gtk_init( argc, argv );
	s->okno = gtk_window_new (GTK_WINDOW_TOPLEVEL); /* Tworzę okno */
}	

void wyswietl_okno( GtkWidget* okno ) { /* Wyświetlam okno */
	
	gtk_widget_show( okno );

}

