#include <stdio.h>
#include "graphics.h"
#include "error_handling.h"
#include "args.h"
#include "mesh.h"

void message( char *tekst, COLOR kolor ) {

	char *color_type;

	switch( kolor ) {
		case GREEN:
			color_type = "\x1b[32m";
			break;
		case RED:
			color_type = "\x1b[31m";
			break;
	}

	printf( "%s%s\x1b[0m", color_type, tekst );
}

/* Wybieram najoptymalniejszy rozmiar pojedyńczej komórki */
int set_graduation( int sx, int sy, int mx, int my ) { /* screen_x, screen_y, mesh_x, mesh_y */

	int grad_x = sx / mx;
	int grad_y = sy / my;

	return grad_x <= grad_y ? grad_x : grad_y;	
}


error set_graphics_settings( struct graphics* ss, struct mesh* siatka, struct args* argumenty ) {
    
    int* width;
    int* height;

	#ifdef DEBUG
		message( "\n#Wchodzę do modułu graphics.\n", GREEN );
	#endif

	ss->x_resolution = argumenty->x_resolution;
	ss->y_resolution = argumenty->y_resolution;

	width = &ss->x_resolution;
  	height = &ss->y_resolution;

    ss->cell_size = set_graduation( ss->x_resolution, ss->y_resolution, siatka->x, siatka->y ); /* obliczam rozmiar komórki */

	if( ss->cell_size < 1 ) {
		message( "*Rozmiar siatki jest większy niż rozdzielczość obrazka.\n", RED );
		return OUT_OF_RANGE;
	}
	ss->mesh_res_x = ss->cell_size * siatka->x;
   	ss->mesh_res_y = ss->cell_size * siatka->y;


	ss->mesh_on_screen_x = (*width -  ss->mesh_res_x)/2; 
    ss->mesh_on_screen_y = (*height -  ss->mesh_res_y)/2; 

	#ifdef DEBUG
		printf( "\tRozmiary okna %s(x,y)=(%d,%d)%s.\n", COLOR_RED, *width, *height, COLOR_RESET );
		printf( "\tRozmiary pojedyńczej komórki %s(x,x) x=%d%s.\n", COLOR_RED, ss->cell_size, COLOR_RESET ); 
		printf( "\tPozycja siatki na obrazie %s(x,y)=(%d, %d)%s.\n", COLOR_RED, ss->mesh_on_screen_x, ss->mesh_on_screen_y, COLOR_RESET );
		printf( "\tRozmiar siatki na obrazie %s(x,y)=(%d, %d)%s.\n", COLOR_RED, ss->mesh_res_x, ss->mesh_res_y, COLOR_RESET );
		
		message( "#Wychodzę z modułu graphics.\n", GREEN );
	#endif

	return FINE;
}
