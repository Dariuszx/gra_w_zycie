#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "mesh.h"
#include "error_handling.h"
#include "graphics.h"

#define PATH_LENGHT 64

error make_dir( char *folder, char *image_folder ) {

    char path[PATH_LENGHT] = "data/";
    int lenght;

	lenght = strlen(path) + strlen(folder);

	
	/* Tworzę folder data */
	if ( mkdir( "data", S_IRWXU|S_IRGRP|S_IXGRP) != 0 && errno != EEXIST ) {
     	printf( "*Problem przy tworzeniu folderu: data" );
       	return MKDIR_ERROR;
    } 
	errno = 0;

	/* Sprawdzam czy długość nazwy folderu nie jest zbyt długa */
    if( lenght >= PATH_LENGHT ) {
        printf( "*Długość nazwy folderu %s jest zbyt duża.\n", folder );
        return OUT_OF_RANGE;
    }

	/* Łącze nazwę folderu z ścieżką */
    if( strcat( path, folder ) == NULL ) {
        return OUT_OF_RANGE;
    }

	/* Dodaję przyrostek informujący, że folder zawiera obrazki */
    if( strcat( path, "_img" ) == NULL ) {
        return OUT_OF_RANGE;
    }

	/* Tworzę folder z obrazkami */
    if( mkdir( path, 0777 ) != 0 && errno != EEXIST ) {
        printf( "*Problem przy tworzeniu folderu: %s.\n", path );
        return MKDIR_ERROR;
    }

	/* Jeżeli folder istnieje zamykam program */
    if( errno == EEXIST ) {
        printf( "*Folder %s już istnieje, proszę wybrać inną nazwę lub użyć polecenia 'make clean_data'.\n", path );
        return MKDIR_ERROR;
    }

	image_folder = path;

	return FINE;
}


error generate_image( struct mesh* siatka, struct graphics* screen_setttings, char* folder, int count ) {


	return FINE;
}
