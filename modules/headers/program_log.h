#ifndef PROGRAM_LOG
	#define PROGRAM_LOG

	#include <stdarg.h>
	#include "error_handling.h"

	struct program_log logi;	

	struct program_log {
		char** log;
		int size;
		int possition;
	};

	error initialize_log( int );
	void add_log( char*, ... );
	error resize_array_log( );
	error write_log( );

#endif
