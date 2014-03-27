#ifndef ERROR_HANDLING
	#define ERROR_HANDLING

    typedef enum { FINE, MALLOC_ERROR, FOPEN_ERROR, OUT_OF_RANGE, FORMAT_ERROR, MKDIR_ERROR, ARG_ERROR } error;
	int error_handling( error );

#endif
