#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define SIZE (1024)
#define ITER (1024 * 1024)

int main(int argc, char** argv)
{
	HighResTimer timer;
	
	double* data = new double[SIZE + 16];
	double* data2 = new double[SIZE + 16];
	memset(data, 0, (SIZE + 16) * sizeof(data[0]));
	memset(data2, 0, (SIZE + 16) * sizeof(data[0]));
	double* addr = (double*) (((char*) data) + OFFSET);
	double* addr2 = (double*) (((char*) data2) + OFFSET);
	printf("Addresses 0x%p 0x%p\n", addr, addr2);
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark(addr, addr2);
	}
	timer.Stop();
	printf("Double Precision, Time: %6.3f sec\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark((float*) addr, (float*) addr2);
	}
	timer.Stop();
	printf("Single Precision, Time: %6.3f sec\n", timer.GetElapsedTime());
	delete[] data;
	delete[] data2;
	return(0);
}
