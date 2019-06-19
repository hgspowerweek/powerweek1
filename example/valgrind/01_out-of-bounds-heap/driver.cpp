#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	int* data = new int[32];

	for (int i = 0;i <= 32;i++) data[i] = 0;

	delete[] data;
	return(0);
}
