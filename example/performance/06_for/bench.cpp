#include "bench.h"

int RunBenchmark(long long int param, int* __restrict data)
{
	int loop1 = 128;
	int loop2 = param / loop1;
	int sum = 0;
	for (int i = 0;i < loop1;i++)
	{
		for (int j = 0;j < loop2;j++)
		{
			sum += data[i * loop2 + j];
		}
	}
	return(sum);
}

int RunBenchmark2(long long int param, int* __restrict data)
{
	int loop1 = 128;
	int loop2 = param / loop1;
	int sum = 0;
	for (int j = 0;j < loop2;j++)
	{
		for (int i = 0;i < loop1;i++)
		{
			sum += data[i * loop2 + j];
		}
	}
	return(sum);
}
