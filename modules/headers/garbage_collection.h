#ifndef GARBAGE_COLLECTION
	#define GARBAGE_COLLECTION

	#include "mesh.h"
	#include "rules.h"

	void free_mesh( struct mesh* );
	void free_rules( struct rules* );	

#endif
