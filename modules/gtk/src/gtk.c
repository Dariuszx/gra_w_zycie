#include <gtk/gtk.h>
#include "gtk.h"
#include "gtk_actions.h"
#include "bool.h"
#include "rules.h"

void gtk_make_window( int *argc, char ***argv, int width, int height ) {
	
	GtkWidget* okno;

	gtk_init( argc, argv );
	gui.okno = gtk_window_new (GTK_WINDOW_TOPLEVEL); /* Tworzę okno */
	okno = gui.okno;

	gtk_window_set_title( GTK_WINDOW( okno ), "GRA" );
/*
	gtk_window_set_default_size( GTK_WINDOW( okno ), (gint)width, (gint)height );
*/
	gtk_window_set_position( GTK_WINDOW( okno ), GTK_WIN_POS_CENTER );
	g_signal_connect( okno, "delete-event", G_CALLBACK (zamkniecie_okna), NULL);
	g_signal_connect( okno, "destroy", G_CALLBACK (destroy), NULL);
	gtk_container_set_border_width (GTK_CONTAINER ( okno ), 0);

	kontenery.main_box = gtk_vbox_new( FALSE, 0 );
	gtk_container_add( GTK_CONTAINER( gui.okno ), kontenery.main_box );

	gtk_menu( &kontenery, &menu, &gui );
}

void gtk_make_header( ) {

	GtkWidget* label_n;
	GtkWidget* label_k;

	GtkWidget* entry_n;
	GtkWidget* entry_k;

	kontenery.table_properties = gtk_table_new( 2, 3, TRUE );
	
	gtk_container_add( GTK_CONTAINER( kontenery.main_box ), kontenery.table_properties );

	label_n = gtk_label_new( "n" );
	label_k = gtk_label_new( "k" );

	entry_n = gtk_entry_new();
	entry_k = gtk_entry_new();

	przyciski.zapisz = gtk_button_new_with_label( "Zapisz" );

	gtk_table_attach( GTK_TABLE( kontenery.table_properties ), label_n, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5 );
	gtk_table_attach( GTK_TABLE( kontenery.table_properties ), label_k, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5 );
	gtk_table_attach_defaults( GTK_TABLE( kontenery.table_properties ), entry_n, 1, 2, 0, 1 );
	gtk_table_attach_defaults( GTK_TABLE( kontenery.table_properties ), entry_k, 1, 2, 1, 2 );	
	gtk_table_attach_defaults( GTK_TABLE( kontenery.table_properties ), przyciski.zapisz, 0, 2, 2, 3 );

}


void gtk_import_data( struct graphics* settings, struct args* argumenty, struct mesh* siatka, struct rules* zasady ) {
	gtk_graphic_settings = settings;
	gtk_args = argumenty;
	gtk_siatka = siatka;
	gtk_rules = zasady;
}

void gtk_show_window( ) { /* Wyświetlam okno */	
	gtk_widget_show_all( gui.okno );
}
