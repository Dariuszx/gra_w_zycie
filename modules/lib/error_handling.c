#include <stdio.h>
#include <errno.h>
#include "error_handling.h"

int error_handling( error error_code ) {

	switch( error_code ) {
		case MKDIR_ERROR:
			switch( errno ) {
				case EACCES:
					printf( "*Search permission is denied on a component of the path prefix.\n" );
					break;
				case EMLINK:
					printf( "*The link count of the parent directory would exceed {LINK_MAX}." );
					break;
				case ENAMETOOLONG:
					printf( "*The length of the path argument exceeds {PATH_MAX} or a pathname component is longer than {NAME_MAX}." );
					break;
				case ENOENT:
					printf( "*A component of the path prefix specified by path does not name an existing directory or path is an empty string." );
					break;
				case ENOSPC:
					printf( "*The file system does not contain enough space to hold the contents of the new directory." );
					break;
				case ENOTDIR:
					printf( "*A component of the path prefix is not a directory." );
					break;
				case EROFS:
					printf( "*The parent directory resides on a read-only file system." );
					break;
			}
			return 1;
			break;
		case OUT_OF_RANGE:
		case MALLOC_ERROR:
		case FOPEN_ERROR:
		case FORMAT_ERROR:
		case ARG_ERROR:
			return 1;
			break;
		case FINE:
			return 0;
			break;
	}
	return 0;
}
