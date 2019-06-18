#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define MAX_SIZE (128 * 1024 * 1024)
#define ITERATIONS 10

int main(int argc, char** argv)
{
	HighResTimer timer;
	for (long long int i = 8;i <= MAX_SIZE;i *= 2)
	{
		int* data = new int[i];
		if (data == NULL) {printf("Memory Allocation Error\n"); exit(1);}
		memset(data, 0, i * sizeof(data[0]));
		timer.Reset();
		timer.Start();
		long long int nIter = MAX_SIZE / i * ITERATIONS;
		for (long long int j = 0;j < nIter;j++)
		{
			RunBenchmark(i, data);
		}
		timer.Stop();
		printf("Size: %9lld bytes, Iterations: %10lld, Time: %6.3f sec, Throughput: %6.3f MB/s\n", i * sizeof(data[0]), nIter, timer.GetElapsedTime(), (double) i * (double) nIter * (double) sizeof(data[0]) / timer.GetElapsedTime() / (double) 1e6);
		delete[] data;
	}
	return(0);
}
