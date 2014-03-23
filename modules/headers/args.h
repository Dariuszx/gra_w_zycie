#ifndef ARGS
	#define ARGS

	#include <stdio.h>

	#define K_DEFAULT 10
	#define N_DEFAULT 100
	#define FILE_IN_DEFAULT "a"
	#define FILE_OUT_DEFAULT "b"
	#define IMAGE_NAME_DEFAULT "img"
	#define RULES_DEFAULT "zasady"

	struct args {
		char *file_in;
		char *file_out;
		char *rules;
		char *image_name;
		int n; /* ilość generacji */
		int k; /* liczba obrazków do wygenerowania */
	};

#endif
