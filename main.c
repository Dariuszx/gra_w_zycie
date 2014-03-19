#include <stdio.h>
#include "args.h"

int main( int argc, char **argv ) {

	struct args argumenty;
	argumenty.b = 132292920;

	printf( "Hello World! cos tam %d \n", argumenty.b );


	return 0;
}
