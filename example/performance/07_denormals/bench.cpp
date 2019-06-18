#include "bench.h"

float RunBenchmark(long long int param, float* __restrict data)
{
	float sum;
	for (int i = 0;i < param;i++) sum += data[i];
	return(sum);
}
