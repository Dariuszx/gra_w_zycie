#ifndef RULES
	#define RULES

	#include "error_handling.h"

	struct rules {
		int *living_cell;
		int *dead_cell;
		
		int living_elements;	
		int dead_elements;
	};

#endif
