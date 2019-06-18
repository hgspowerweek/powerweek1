#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define SIZE (1024)
#define ITER (1024 * 16)

int main(int argc, char** argv)
{
	HighResTimer timer;
	float* data = new float[SIZE];
	memset(data, 0, SIZE * sizeof(data[0]));
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark(SIZE, data);
	}
	timer.Stop();
	printf("Zero Values, Time: %6.3f\n", timer.GetElapsedTime());
	for (int i = 0;i < SIZE;i++) *((int*) &data[i]) = i;
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark(SIZE, data);
	}
	timer.Stop();
	printf("Weird Values, Time: %6.3f\n", timer.GetElapsedTime());
	delete[] data;
	return(0);
}
