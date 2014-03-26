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

error set_graphics_settings( struct graphics* screen_settings, struct mesh* siatka, struct args* argumenty ) {
    
	int max_res_mesh, min_res_screen; /* dobieram maksymalne rozmiary krawędzi */

    int* width;
    int* height;

	#ifdef DEBUG
		message( "\n#Wchodzę do modułu graphics.\n", GREEN );
	#endif

	screen_settings->x_resolution = argumenty->x_resolution;
	screen_settings->y_resolution = argumenty->y_resolution;

	width = &screen_settings->x_resolution;
  	height = &screen_settings->y_resolution;

    max_res_mesh = siatka->x >= siatka->y ? siatka->x : siatka->y; /* zapisuję największy rozmiar */
    min_res_screen = *width <= *height ? *width : *height;

    screen_settings->cell_size = min_res_screen / max_res_mesh; /* obliczam rozmiar komórki */

	screen_settings->mesh_res_x = screen_settings->cell_size * siatka->x;
    screen_settings->mesh_res_y = screen_settings->cell_size * siatka->y;


	screen_settings->mesh_on_screen_x = (*width -  screen_settings->mesh_res_x)/2; 
    screen_settings->mesh_on_screen_y = (*height -  screen_settings->mesh_res_y)/2; 

	#ifdef DEBUG
		printf( "\tRozmiary okna %s(x,y)=(%d,%d)%s.\n", COLOR_RED, *width, *height, COLOR_RESET );
		printf( "\tRozmiary pojedyńczej komórki %s(x,x) x=%d%s.\n", COLOR_RED, screen_settings->cell_size, COLOR_RESET ); 
		printf( "\tPozycja siatki na obrazie %s(x,y)=(%d, %d)%s.\n", COLOR_RED, screen_settings->mesh_on_screen_x, screen_settings->mesh_on_screen_y, COLOR_RESET );
		printf( "\tRozmiar siatki na obrazie %s(x,y)=(%d, %d)%s.\n", COLOR_RED, screen_settings->mesh_res_x, screen_settings->mesh_res_y, COLOR_RESET );
		
		message( "#Wychodzę z modułu graphics.\n", GREEN );
	#endif

	return FINE;
}
