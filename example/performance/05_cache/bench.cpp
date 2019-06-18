#include "bench.h"

int RunBenchmark(long long int param, int* __restrict data)
{
	int sum = 0;
	for (long long int i = 0;i < param;i+=16)
	{
		sum += data[i];
	}
	return(sum);
}
