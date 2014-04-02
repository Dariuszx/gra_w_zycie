/* W tym pliku znajdują sie funkcje wywołane w zależności od akcji w programie */

#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "error_handling.h"
#include "data_loading.h"
#include "gtk.h"

void wybierz_pliki( GtkWidget* widget, gpointer okno, char* file_name ) {

	GtkWidget* dialog;
	char* file_path;

	dialog = gtk_file_chooser_dialog_new( "Otwórz...", GTK_WINDOW( okno ), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL,
											GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL );

	if( gtk_dialog_run( GTK_DIALOG( dialog ) ) == GTK_RESPONSE_ACCEPT ) {
		file_path = gtk_file_chooser_get_filename( GTK_FILE_CHOOSER( dialog ) );
		strcpy( file_name, file_path );
	}
	gtk_widget_destroy( dialog );
}


void otworz_siatke( GtkWidget *widget, gpointer okno ) {

	char file_name[128];
	
	wybierz_pliki( widget, okno, file_name );	

	/* TODO arg_error_handling */
	if ( data_loading( gtk_siatka, file_name ) != FINE ) printf( "Nie udało się wczytać siatki" );

}

gboolean zamkniecie_okna( GtkWidget *okno, GdkEvent *event, gpointer data ) {
    return FALSE;
}

void destroy( GtkWidget *okno, gpointer data ) {
    gtk_main_quit ();
}

