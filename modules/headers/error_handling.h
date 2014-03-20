#ifndef ERROR_HANDLING
	#define ERROR_HANDLING

    typedef enum { FINE, MALLOC_ERROR, FOPEN_ERROR, OUT_OF_RANGE } error;
	int error_handling( error );

#endif
