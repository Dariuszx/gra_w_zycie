#ifndef GARBAGE_COLLECTION
	#define GARBAGE_COLLECTION

	#include "mesh.h"
	#include "rules.h"
	#include "program_log.h"

	void free_mesh( struct mesh* );
	void free_rules( struct rules* );	
	void free_log( struct program_log* );


#endif
