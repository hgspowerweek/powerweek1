#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define ITER (1024 * 1024 * 128)

int main(int argc, char** argv)
{
	HighResTimer timer;
	
	int data[16];
	for (int i = 0;i < 16;i++) data[i] = i;
	int retval = 0;
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		retval = RunBenchmark(data);
	}
	timer.Stop();
	printf("Time: %6.3f sec (Result %d)\n", timer.GetElapsedTime(), retval);
	return(0);
}
