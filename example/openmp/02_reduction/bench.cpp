#include "bench.h"
#include <math.h>
#include <vector>
#include <omp.h>

int ComplexFunction(int i)
{
	return((int) log(sin((double) i) + pow(i % 13, 2.5f) - atan(i % 25 - 12) + sqrt(sqrt(sqrt(sqrt((double) i))))));
}

int RunBenchmark(long long int param, int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < param;i++)
	{
		sum += ComplexFunction(data[i]);
	}
	return(sum);
}

int RunBenchmark2(long long int param, int* __restrict data)
{
	std::vector<int> sums(omp_get_max_threads());
	int nThreads;
	#pragma omp parallel for
	for (int i = 0;i < param;i++)
	{
		if (i == 0 && omp_get_thread_num() == 0) nThreads = omp_get_num_threads();
		sums[omp_get_thread_num()] += ComplexFunction(i);
	}
	for (int i = 1;i < nThreads;i++) sums[0] += sums[i];
	return(sums[0]);
}

int RunBenchmark3(long long int param, int* __restrict data)
{
	int sum = 0;
	#pragma omp parallel for reduction (+ : sum)
	for (int i = 0;i < param;i++)
	{
		sum += ComplexFunction(i);
	}
	return(sum);
}
