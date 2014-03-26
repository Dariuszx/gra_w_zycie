#ifndef GENERATE_PNG
	#define GENERATE_PNG

	#include "mesh.h"
	#include "error_handling.h"

	error make_dir( char*, char* );
	error generate_ppm( struct mesh*, char*, int );

#endif
