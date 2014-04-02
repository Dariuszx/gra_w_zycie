#ifndef GTK_ACTIONS
	#define GTK_ACTIONS

	#include <gtk/gtk.h>
	
	void otworz_siatke( GtkWidget*, gpointer );
	void otworz_zasady( GtkWidget*, gpointer );
	gboolean zamkniecie_okna( GtkWidget*, GdkEvent*, gpointer );
	void destroy( GtkWidget*, gpointer );

#endif
