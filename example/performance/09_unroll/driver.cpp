#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define SIZE 1024
#define ITER (1024 * 1024 * 16)

int main(int argc, char** argv)
{
	HighResTimer timer;

	int* data = new int[SIZE];
	memset(data, 0, SIZE * sizeof(data[0]));
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark(SIZE, data);
	}
	timer.Stop();
	printf("Manual Unroll 0 - Time: %6.3f sec\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark8(SIZE, data);
	}
	timer.Stop();
	printf("Manual Unroll 8 - Time: %6.3f sec\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark16(SIZE, data);
	}
	timer.Stop();
	printf("Manual Unroll 16 - Time: %6.3f sec\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark64(SIZE, data);
	}
	timer.Stop();
	printf("Manual Unroll 64 - Time: %6.3f sec\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark256(SIZE, data);
	}
	timer.Stop();
	printf("Manual Unroll 256 - Time: %6.3f sec\n", timer.GetElapsedTime());
	delete[] data;
	return(0);
}
