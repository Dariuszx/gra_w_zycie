#ifndef GTK_ACTIONS
	#define GTK_ACTIONS

	#include <gtk/gtk.h>

	void wybierz_pliki( GtkWidget*, gpointer );
	gboolean zamkniecie_okna( GtkWidget*, GdkEvent*, gpointer );
	void destroy( GtkWidget*, gpointer );

#endif
