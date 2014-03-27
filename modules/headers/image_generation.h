#ifndef GENERATE_PNG
	#define GENERATE_PNG

	#define X_RESOLUTION 800
	#define Y_RESOLUTION 800

	#include "mesh.h"
	#include "error_handling.h"
	#include "graphics.h"

	error make_dir( char*, char* );
	error generate_image( struct mesh*, struct graphics*, char*, int );

#endif
