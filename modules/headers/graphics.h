#ifndef GRAPHICS
	#define GRAPHICS

	#define X_RESOLUTION 800
	#define Y_RESOLUTION 800
	#define MAX_X_RES 1920
	#define MAX_Y_RES 1680

	#define COLOR_GREEN "\x1b[32m"
	#define COLOR_RED "\x1b[31m"
	#define COLOR_RESET "\x1b[0m"

	#include "error_handling.h"
	#include "mesh.h"
	#include "args.h"

	typedef enum { GREEN, RED } COLOR;

	struct graphics {
		int x_resolution; /* Wymiary całego obrazu */
		int y_resolution;
		int cell_size; /* Rozmiar komórki */
		int mesh_res_x; /* Rozmiar siatki w pikselach na obrazie */
		int mesh_res_y;
		int mesh_on_screen_x; /* Współrzędne lewego górnego krańca siatki względem całego obrazu */
		int mesh_on_screen_y;
	};

	error set_graphics_settings( struct graphics*, struct mesh*, struct args* );
	void message( char*, COLOR );

#endif
