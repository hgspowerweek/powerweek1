#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	int bla;
	
	if (argc > 1) bla = atoi(argv[1]);

	if (bla > 0) printf("Val %d\n", bla);

	return(0);
}
