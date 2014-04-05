#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "mesh.h"
#include "error_handling.h"
#include "program_log.h"

#define PATH_LENGHT 64 /* Maksymalna długość ścieżki do pliku, w którym zostanie zapisana siatka komórek */

error data_saving( struct mesh* siatka, char* file_out ) {

	char path[PATH_LENGHT] = "data/";
	int lenght; /* długość ścieżki pliku do zapisu */
	FILE *file;
	int x, y;

	if( mkdir( "data", 0777 ) != 0 && errno != EEXIST ) {
		add_log( "#Problem przy tworzeniu folderu: data." );
		return MKDIR_ERROR;
	} 
	
	lenght = strlen( path ) + strlen( file_out );

	if( lenght >= PATH_LENGHT ) {
		add_log( "#Długość nazwy pliku %s jest zbyt duża.", file_out );
		return OUT_OF_RANGE;
	}

	if( strcat( path, file_out ) == NULL ) {
		return OUT_OF_RANGE;
	}

	if( ( file = fopen( path, "w" )) == NULL ) {
		add_log( "#Nie udało się otworzyć pliku do zapisu %s.", path );
		return FOPEN_ERROR;
	}

	fprintf( file, "%d %d", siatka->x, siatka->y );
	
	for( y=0; y < siatka->y; y++ ) {
		for( x=0; x < siatka->x; x++ ) {
			if( siatka->siatka[x][y] == 1 )
				fprintf( file, "\n%d %d", x, y ); 
		}
	}

	fclose( file );

	return FINE;
}
