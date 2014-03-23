#ifndef CELLULAR_AUTOMATON
	#define CELLULAR_AUTOMATON

	#include "mesh.h"
	#include "args.h"
	#include "rules.h"
	#include "error_handling.h"

	error cellular_automaton( struct mesh*, struct args* );
	error select_rules( struct args*, struct rules* );
	error formation_generation( struct mesh*, struct args*, struct rules* );

#endif
