#ifndef ERROR_HANDLING
	#define ERROR_HANDLING

	#define MESSAGE_LENGHT 128

	char error_message[MESSAGE_LENGHT];
	char warning_message[MESSAGE_LENGHT];

    typedef enum { FINE, MALLOC_ERROR, FOPEN_ERROR, OUT_OF_RANGE, FORMAT_ERROR, MKDIR_ERROR, ARG_ERROR, GTK_FINE } error;
	int error_handling( error );

#endif
