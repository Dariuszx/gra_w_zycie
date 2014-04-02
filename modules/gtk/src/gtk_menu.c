/* W tym pliku znajduje się implementacja menu głównego */
#include <gtk/gtk.h>
#include "gtk.h"
#include "gtk_actions.h"

void gtk_menu( struct gtk_boxes* kontenery, struct gtk_menu* menu, struct gtk_graphics* gui ) {

    kontenery->menu_box = gtk_vbox_new( FALSE, 0 ); /* Tworzę kontener */
    gtk_container_add( GTK_CONTAINER( kontenery->main_box ), kontenery->menu_box ); /* Dodaję kontener do menu głównego */

    menu->pasek = gtk_menu_bar_new(); /* Tworzę pasek menu */

    menu->menu_plik = gtk_menu_new(); /* Tworzę submenu */
    menu->menu_dane = gtk_menu_new();
    menu->menu_pomoc = gtk_menu_new();

    menu->plik = gtk_menu_item_new_with_mnemonic("_Plik"); /* Tworzę kolejne przyciski dla submenu */
        menu->zapisz = gtk_menu_item_new_with_mnemonic("_Zapisz");
        menu->wyjdz = gtk_image_menu_item_new_from_stock( GTK_STOCK_QUIT, NULL );

    menu->dane = gtk_menu_item_new_with_mnemonic("_Dane");
        menu->otworz_siatke = gtk_menu_item_new_with_mnemonic("_Otwórz siatke");
        menu->otworz_zasady = gtk_menu_item_new_with_mnemonic("_Otwórz zasady");

    menu->pomoc = gtk_menu_item_new_with_mnemonic("_Pomoc");
        menu->oprogramie = gtk_menu_item_new_with_mnemonic("_O programie");


	/* Dodaje kolejne opcje do submenu */
    gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu->plik ), menu->menu_plik );
        gtk_menu_shell_append( GTK_MENU_SHELL( menu->menu_plik ), menu->zapisz );
        gtk_menu_shell_append( GTK_MENU_SHELL( menu->menu_plik ), menu->wyjdz );

    gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu->dane ), menu->menu_dane );
        gtk_menu_shell_append( GTK_MENU_SHELL( menu->menu_dane ), menu->otworz_siatke );
        gtk_menu_shell_append( GTK_MENU_SHELL( menu->menu_dane ), menu->otworz_zasady );

    gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu->pomoc ), menu->menu_pomoc );
        gtk_menu_shell_append( GTK_MENU_SHELL( menu->menu_pomoc ), menu->oprogramie );

	/* Dodaję submenu do menu głównego */
    gtk_menu_shell_append( GTK_MENU_SHELL( menu->pasek ), menu->plik );
    gtk_menu_shell_append( GTK_MENU_SHELL( menu->pasek ), menu->dane );
    gtk_menu_shell_append( GTK_MENU_SHELL( menu->pasek ), menu->pomoc );

	/* Dodaję menu główne do kontenera zawierajacego menu */
	gtk_box_pack_start( GTK_BOX( kontenery->menu_box ), menu->pasek, FALSE, FALSE, 0 );

	/* Definiuję akcje po uruchomieniu konkretnej opcji */
  	g_signal_connect( G_OBJECT( menu->otworz_siatke ), "activate", G_CALLBACK( otworz_siatke ), NULL );
   	g_signal_connect( G_OBJECT( menu->otworz_zasady ), "activate", G_CALLBACK( otworz_zasady ), NULL );
 	g_signal_connect( G_OBJECT( menu->wyjdz ), "activate", G_CALLBACK( gtk_main_quit ), NULL);

	/* Wyświetlam menu w oknie */
 	gtk_widget_show_all( gui->okno );
}
