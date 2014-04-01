/* W tym pliku znajdują sie funkcje wywołane w zależności od akcji w programie */

#include <gtk/gtk.h>
#include "gtk.h"

void wybierz_pliki( GtkWidget *widget, gpointer okno ) {

    GtkWidget *dialog;
    char *nazwa_pliku;

    dialog = gtk_file_chooser_dialog_new( "Otwórz...", GTK_WINDOW( okno ), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

    if ( gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT ) {
        nazwa_pliku = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    }

    gtk_widget_destroy (dialog);
}


gboolean zamkniecie_okna( GtkWidget *okno, GdkEvent *event, gpointer data ) {
    return FALSE;
}

void destroy( GtkWidget *okno, gpointer data ) {
    gtk_main_quit ();
}

