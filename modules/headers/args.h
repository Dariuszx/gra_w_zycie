#ifndef ARGS
	#define ARGS

	#include <stdio.h>

	#define K_DEFAULT 10
	#define N_DEFAULT 100
	#define FILE_IN_DEFAULT "a"
	#define FILE_OUT_DEFAULT "mesh"
	#define IMAGE_NAME_DEFAULT "obrazy"
	#define RULES_DEFAULT "zasady"

	struct args {
		char *file_in;
		char *file_out;
		char *rules;
		char *image_name;
		char *image_folder;
		int x_resolution;
		int y_resolution;
		int n; /* ilość generacji */
		int k; /* liczba obrazków do wygenerowania */
	};

#endif
