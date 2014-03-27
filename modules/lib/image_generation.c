#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "mesh.h"
#include "error_handling.h"
#include "graphics.h"

#define PATH_LENGHT 128


error generate_image( struct mesh* siatka, struct graphics* s, char* folder, int count ) {

	char image_name[PATH_LENGHT];
	FILE *file;	
	int x, y;
	int ratio_x, ratio_y;	

	static unsigned char color[3];
	int xmc = s->mesh_on_screen_x;
 	int ymc = s->mesh_on_screen_y;
	
	int color_change = 0;
	
	sprintf( image_name, "%s/img%d.ppm", folder, count );

	if( ( file = fopen( image_name, "wb" )) == NULL ) return FOPEN_ERROR;

	fprintf( file, "P6\n%d %d\n255\n", s->x_resolution, s->y_resolution );

	for( y = 0; y < s->y_resolution; y++ ) {
		for( x = 0; x < s->x_resolution; x++ ) {
			 
			if( x >= xmc && x <= (s->x_resolution - xmc) && y >= ymc && y <= ( s->y_resolution - ymc ) ) {
				
				/* Krawędzie komórek */	
				if( (x - xmc)%(s->cell_size+1) == 0 || (y - ymc)%(s->cell_size+1) == 0 ) {
              		color[0]= 66; /* red */
                 	color[1]= 66; /* green */
                   	color[2]= 66; /* blue */
				} else {
					ratio_x = (x - xmc) / (s->cell_size+1);
               		ratio_y = (y - ymc) / (s->cell_size+1); 
					
					/* Komórka żywa */
					if( siatka->siatka[ratio_x][ratio_y] == 1 ) {
						color[0]= 49; 
            			color[1]= 101; 
            			color[2]= 148; 
					} else { /* martwa */
			         	color[0]= 204; 
                      	color[1]= 204; 
                     	color[2]= 204; 
					}
				}
			} else { /* obszar poza siatką */
				
          		color[0]= 0; /* red */
           		color[1]= 0; /* green */
          		color[2]= 0; /* blue */
			}
          	fwrite( color, 1, 3, file );			
		}
	}

    return FINE;
}

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

	sprintf( image_folder, "%s", path);

	return FINE;
}
