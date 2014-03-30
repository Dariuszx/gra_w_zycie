#include <gtk/gtk.h>
#include "gtk.h"
#include "bool.h"

struct graphics_gtk gui;
struct buttons_gtk przyciski;
struct boxes_gtk kontenery;
struct menu_gtk menu;

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
	gtk_container_set_border_width (GTK_CONTAINER ( okno ), 0);
}


void dodaj_przycisk( BUTTON_GTK TYP, char* title ) {

	switch( TYP ) {
		case QUIT:
			przyciski.quit = gtk_button_new_with_label( title  );
			g_signal_connect_swapped( przyciski.quit, "clicked", G_CALLBACK(gtk_widget_destroy), gui.okno);
		
		break;
		case START:
			przyciski.start = gtk_button_new_with_label( title  );
           	gtk_widget_set_size_request( przyciski.start, 100, 100 );
           	g_signal_connect_swapped( przyciski.start, "clicked", G_CALLBACK(gtk_widget_destroy), gui.okno);
           	gtk_widget_show( przyciski.start );
	}

}


void wybierz_pliki(GtkWidget *widget, gpointer okno) {
    
	GtkWidget *dialog;
	char *nazwa_pliku; 

	dialog = gtk_file_chooser_dialog_new( "Otwórz...", GTK_WINDOW( okno ), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
 
    if ( gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT ) { 
		nazwa_pliku = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    }
 
    gtk_widget_destroy (dialog);
}


void stworz_menu( ) {

    kontenery.menu_box = gtk_vbox_new( FALSE, 0 );
  	gtk_container_add( GTK_CONTAINER( gui.okno ), kontenery.menu_box );

	menu.pasek = gtk_menu_bar_new();
	
	menu.menu_plik = gtk_menu_new();
	menu.menu_dane = gtk_menu_new();	
	menu.menu_pomoc = gtk_menu_new();

 	menu.plik = gtk_menu_item_new_with_mnemonic("_Plik");
		menu.zapisz = gtk_menu_item_new_with_mnemonic("_Zapisz");
		menu.wyjdz = gtk_image_menu_item_new_from_stock( GTK_STOCK_QUIT, NULL );

	menu.dane = gtk_menu_item_new_with_mnemonic("_Dane");
        menu.otworz_siatke = gtk_menu_item_new_with_mnemonic("_Otwórz siatke");
		menu.otworz_zasady = gtk_menu_item_new_with_mnemonic("_Otwórz zasady");

    menu.pomoc = gtk_menu_item_new_with_mnemonic("_Pomoc");
        menu.oprogramie = gtk_menu_item_new_with_mnemonic("_O programie");


   	gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu.plik ), menu.menu_plik ); 
		gtk_menu_shell_append( GTK_MENU_SHELL( menu.menu_plik ), menu.zapisz );
		gtk_menu_shell_append( GTK_MENU_SHELL( menu.menu_plik ), menu.wyjdz );

  	gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu.dane ), menu.menu_dane );
       	gtk_menu_shell_append( GTK_MENU_SHELL( menu.menu_dane ), menu.otworz_siatke );
       	gtk_menu_shell_append( GTK_MENU_SHELL( menu.menu_dane ), menu.otworz_zasady );

	gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu.pomoc ), menu.menu_pomoc );
  		gtk_menu_shell_append( GTK_MENU_SHELL( menu.menu_pomoc ), menu.oprogramie );
	
	gtk_menu_shell_append( GTK_MENU_SHELL( menu.pasek ), menu.plik );
	gtk_menu_shell_append( GTK_MENU_SHELL( menu.pasek ), menu.dane );
	gtk_menu_shell_append( GTK_MENU_SHELL( menu.pasek ), menu.pomoc );

    gtk_box_pack_start( GTK_BOX( kontenery.menu_box ), menu.pasek, FALSE, FALSE, 0 );
	
	g_signal_connect( G_OBJECT( menu.otworz_siatke ), "activate", G_CALLBACK( wybierz_pliki ), NULL );
    g_signal_connect( G_OBJECT( menu.otworz_zasady ), "activate", G_CALLBACK( wybierz_pliki ), NULL );

	g_signal_connect( G_OBJECT( menu.wyjdz ), "activate", G_CALLBACK( gtk_main_quit ), NULL);

	gtk_widget_show_all( gui.okno );
}


void wyswietl_okno( ) { /* Wyświetlam okno */
	
	gtk_widget_show( gui.okno );

}



