#include "bench.h"

void RunBenchmark(long long int param, position* __restrict data)
{
	for (int i = 0;i < param;i++)
	{
		data[i].r2 = data[i].x * data[i].x + data[i].y * data[i].y + data[i].z * data[i].z;
	}
}

void RunBenchmark2(long long int param, position_soa& __restrict data2)
{
	for (int i = 0;i < param;i++)
	{
		data2.r2[i] = data2.x[i] * data2.x[i] + data2.y[i] * data2.y[i] + data2.z[i] * data2.z[i];
	}
}
