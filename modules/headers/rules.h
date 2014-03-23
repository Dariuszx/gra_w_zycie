/*
	Struktura zawiera dwie tablice zasad dla komórek żywych i martwych.
	Każdy element tablicy zawiera liczbę sąsiadujących żywych komórek
	- tak aby komórka pozostała żywa.
	Np. Jeżeli living_cell[0] = 5. To komórka pozostaje żywa jeżeli posiada
	- dokłądnie 5 żywych sąsiadów.
	Zaś jeżeli dead_cell[0] = 5. To komórka martwa staje się żywa, jeżeli
	- graniczy z 5 żywymi komórkami.
*/

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
