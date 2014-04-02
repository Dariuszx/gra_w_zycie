#ifndef CELLULAR_AUTOMATON
	#define CELLULAR_AUTOMATON

	#include "mesh.h"
	#include "args.h"
	#include "rules.h"
	#include "error_handling.h"
	#include "graphics.h"

	error cellular_automaton( struct mesh*, struct args*, struct graphics* );
	error select_rules( char*, struct rules* );
	error formation_generation( struct mesh*, struct rules* );

#endif
