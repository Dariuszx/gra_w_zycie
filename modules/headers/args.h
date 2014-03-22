#ifndef ARGS
	#define ARGS

	#include <stdio.h>

	#define K_DEFAULT 10
	#define N_DEFAULT 100
	#define FILE_IN_DEFAULT "a"
	#define FILE_OUT_DEFAULT "b"
	#define IMAGE_NAME_DEFAULT "img"

	struct args {
		char *file_in;
		char *file_out;
		int n; /* ilość generacji */
		int k; /* liczba obrazków do wygenerowania */
		char *image_name; /* wzór nazewnictwa obrazków */
	};

#endif
