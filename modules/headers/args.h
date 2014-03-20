#ifndef ARGS
	#define ARGS

	#include <stdio.h>

	struct args {
		FILE *file_in;
		FILE *file_out;
		int n; /* ilość generacji */
		int k; /* liczba obrazków do wygenerowania */
		char *image_name; /* wzór nazewnictwa obrazków */
	};

#endif
