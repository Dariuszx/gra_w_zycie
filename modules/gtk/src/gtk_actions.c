/* W tym pliku znajdują sie funkcje wywołane w zależności od akcji w programie */

#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "error_handling.h"
#include "data_loading.h"
#include "cellular_automaton.h"
#include "gtk.h"
#include "bool.h"

void gtk_message_dialog( gpointer okno, char* title, char* message, GtkMessageType message_type ) {
	GtkWidget* dialog;
	dialog = gtk_message_dialog_new( GTK_WINDOW( okno ), GTK_DIALOG_DESTROY_WITH_PARENT, message_type, GTK_BUTTONS_OK, message );
	gtk_window_set_title( GTK_WINDOW( dialog ), title );
	gtk_dialog_run( GTK_DIALOG( dialog ) );
	gtk_widget_destroy( dialog );
}

void wybierz_pliki( GtkWidget* widget, gpointer okno, char* file_name, bool* czy_otwarto ) {

	GtkWidget* dialog;
	char* file_path;

	dialog = gtk_file_chooser_dialog_new( "Otwórz...", GTK_WINDOW( okno ), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL,
											GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL );

	if( gtk_dialog_run( GTK_DIALOG( dialog ) ) == GTK_RESPONSE_ACCEPT ) {
		file_path = gtk_file_chooser_get_filename( GTK_FILE_CHOOSER( dialog ) );
		strcpy( file_name, file_path );
		*czy_otwarto = true;
	}
	gtk_widget_destroy( dialog );
}


void otworz_siatke( GtkWidget *widget, gpointer okno ) {

	char file_name[128];
	bool status = false;

	wybierz_pliki( widget, okno, file_name, &status );	

	if( status == true ) {
		if ( data_loading( gtk_siatka, file_name ) != FINE ) gtk_message_dialog( gui.okno, "Błąd", error_message, GTK_MESSAGE_ERROR );
		else gtk_message_dialog( gui.okno, "OK", "Pomyślnie wczytano plik z siatką.", GTK_MESSAGE_INFO );
	}
}

void otworz_zasady( GtkWidget *widget, gpointer okno ) {

    char file_name[128];
	bool status = false;

    wybierz_pliki( widget, okno, file_name, &status );

    if( status == true ) {
		if ( select_rules( file_name, gtk_rules ) != FINE ) gtk_message_dialog( gui.okno, "Błąd", error_message, GTK_MESSAGE_ERROR );
    	else gtk_message_dialog( gui.okno, "OK", "Pomyślnie wczytano plik z zasadami.", GTK_MESSAGE_INFO );
	}
}


gboolean zamkniecie_okna( GtkWidget *okno, GdkEvent *event, gpointer data ) {
    return FALSE;
}

void destroy( GtkWidget *okno, gpointer data ) {
    gtk_main_quit ();
}

