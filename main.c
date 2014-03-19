#include <stdio.h>
#include "args.h"
#include "arg_handling.h"

int main( int argc, char **argv ) {

	struct args argumenty;
	argumenty.b = 132292920;

	printf( "Hello World! cos tam %d \n", argumenty.b );
	arg_handling();


#ifdef DEBUG
	printf( "To jest cześć do debugowania niewidoczna z poziomu zwykłej kompilacji.\n" );
#endif


	return 0;
}
