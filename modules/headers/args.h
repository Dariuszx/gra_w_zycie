#ifndef ARGS
	#define ARGS

	#include <stdio.h>
	#include "bool.h"

	#define K_DEFAULT 10
	#define N_DEFAULT 100
	#define FILE_IN_DEFAULT "examples/glider_gun"
	#define FILE_OUT_DEFAULT "mesh"
	#define IMAGE_NAME_DEFAULT "obrazy"
	#define RULES_DEFAULT "examples/zasady"

	struct args {
		char *file_in;
		char *file_out;
		char *rules;
		char *image_name;
		char *image_folder;
		bool graphics_ui;
		int x_resolution;
		int y_resolution;
		int n; /* ilość generacji */
		int k; /* liczba obrazków do wygenerowania */
	};

#endif
