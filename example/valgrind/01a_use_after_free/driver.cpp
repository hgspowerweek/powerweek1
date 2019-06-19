#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	int* data = new int[32];
	delete[] data;
	data[0] = 0;

	return(0);
}
