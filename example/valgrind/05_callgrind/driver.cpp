#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "intermediate.h"

#define SIZE (1024)
#define ITER (1024 * 10)

class_virtual c_virt;

int main(int argc, char** argv)
{
	int* data = new int[SIZE];
	memset(data, 0, SIZE * sizeof(data[0]));
	for (int i = 0;i < ITER;i++)
	{
		loop_virtual2(SIZE, data);
	}
	for (int i = 0;i < ITER;i++)
	{
		loop_virtual(&c_virt, SIZE, data);
	}
	for (int i = 0;i < ITER;i++)
	{
		loop_basic(SIZE, data);
	}
	for (int i = 0;i < ITER;i++)
	{
		loop_inline(SIZE, data);
	}
	delete[] data;
	return(0);
}
