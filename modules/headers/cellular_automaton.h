#ifndef CELLULAR_AUTOMATON
	#define CELLULAR_AUTOMATON

	#include "mesh.h"
	#include "args.h"
	#include "rules.h"

	int cellular_automaton( struct mesh*, struct args* );
	int select_rules( struct args*, struct rules* );
	int formation_generation( struct mesh*, struct args*, struct rules* );

#endif
