#include <stdio.h>
#include "error_handling.h"

int error_handling( error error_code ) {

	switch( error_code ) {
		case OUT_OF_RANGE:
		case MALLOC_ERROR:
		case FOPEN_ERROR:
			return 1;
			break;
		case FINE:
			return 0;
			break;
	}
	return 0;
}
