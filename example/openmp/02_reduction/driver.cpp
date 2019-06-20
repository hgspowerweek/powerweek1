#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "timer.h"

#define MAX_SIZE (1024 * 1024 * 16)
#define ITER (16 * 1024 * 1024 / SIZE)

int main(int argc, char** argv)
{
	HighResTimer timer;
	for (int SIZE = MAX_SIZE;SIZE > 0;SIZE /= 2)
	{
		printf("SIZE: %d\n", SIZE);
		int* data = new int[SIZE];
		for (int i = 0;i < SIZE;i++) data[i] = i + 1;
		int retval = 0;
		timer.Reset();
		timer.Start();
		for (int i = 0;i < ITER;i++)
		{
			retval = RunBenchmark(SIZE, data);
		}
		timer.Stop();
		printf("\tNormal, Time: %6.3f (Result %d)\n", timer.GetElapsedTime(), retval);
		timer.Reset();
		timer.Start();
		for (int i = 0;i < ITER;i++)
		{
			retval = RunBenchmark2(SIZE, data);
		}
		timer.Stop();
		printf("\tOpenMP (manual), Time: %6.3f (Result %d)\n", timer.GetElapsedTime(), retval);
		timer.Start();
		for (int i = 0;i < ITER;i++)
		{
			retval = RunBenchmark3(SIZE, data);
		}
		timer.Stop();
		printf("\tOpenMP (reduction), Time: %6.3f (Result %d)\n", timer.GetElapsedTime(), retval);
		delete[] data;
	}
	return(0);
}
