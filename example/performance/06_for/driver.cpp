#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define SIZE (1024 * 1024 * 1)

int main(int argc, char** argv)
{
	HighResTimer timer;
	int* data = new int[SIZE];
	for (int i = 0;i < SIZE;i++) data[i] = i;
	int retval = 0;
	timer.Reset();
	timer.Start();
	for (int i = 0;i < 128;i++)
	{
		retval = RunBenchmark(SIZE, data);
	}
	timer.Stop();
	printf("Version 1, Time: %6.3f (Result %d)\n", timer.GetElapsedTime(), retval);
	timer.Reset();
	timer.Start();
	for (int i = 0;i < 128;i++)
	{
		retval = RunBenchmark2(SIZE, data);
	}
	timer.Stop();
	printf("Version 1, Time: %6.3f (Result %d)\n", timer.GetElapsedTime(), retval);
	delete[] data;
	return(0);
}
