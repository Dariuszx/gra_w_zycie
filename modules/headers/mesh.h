#ifndef MESH
	#define MESH

	#include "error_handling.h"

	#define MAX_X 512
	#define MAX_Y 512

	struct mesh {
		int **siatka;
		int x;
		int y;
	};

	error copy_mesh( struct mesh*, struct mesh* );
	error make_mesh( struct mesh*, int, int );

#endif
