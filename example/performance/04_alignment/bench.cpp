#include "bench.h"

void RunBenchmark(double* __restrict data, double* __restrict data2)
{
	for (int i = 0;i < 1024;i++)
	{
		data[i] = data2[i] * 3 + 2;
	}
}

void RunBenchmark(float* __restrict data, float* __restrict data2)
{
	for (int i = 0;i < 2048;i++)
	{
		data[i] = data2[i] * 3 + 2;
	}
}

