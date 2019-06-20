#include "bench.h"
#include <math.h>

int ComplexFunction(int i)
{
	return((int) log(sin((double) i) + pow(i % 13, 2.5f) - atan(i % 25 - 12) + sqrt(sqrt(sqrt(sqrt((double) i))))));
}

int RunBenchmark(long long int param, int* __restrict data)
{
	for (int i = 0;i < param;i++)
	{
		data[i] = ComplexFunction(i);
	}
	return(0);
}

int RunBenchmark2(long long int param, int* __restrict data)
{
	#pragma omp parallel for
	for (int i = 0;i < param;i++)
	{
		data[i] = ComplexFunction(i);
	}
	return(0);
}
