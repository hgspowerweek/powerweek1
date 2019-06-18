#include "bench.h"

int RunBenchmark(int* __restrict data)
{
	int sum = 0;
	for (int i = 0;i < 16;i++) sum += data[i];
	return(sum);
}
