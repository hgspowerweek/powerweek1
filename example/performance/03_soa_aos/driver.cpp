#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "../base/timer.h"

#define SIZE (1024 * 1024 * 128)
#define ITER 8

int main(int argc, char** argv)
{
	HighResTimer timer;
	position* data = new position[SIZE];
	position_soa data2;
	data2.x = new float[SIZE];
	data2.y = new float[SIZE];
	data2.z = new float[SIZE];
	data2.r2 = new float[SIZE];
	memset(data, 0, SIZE * sizeof(data[0]));
	memset(data2.r2, 0, SIZE * sizeof(data2.r2[0]));
	for (int i = 0;i < SIZE;i++)
	{
		data[i].x = data[i].y = data[i].z = (float) i / SIZE;
		data2.x[i] = data2.y[i] = data2.z[i] = (float) i / SIZE;
	}
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark(SIZE, data);
	}
	timer.Stop();
	printf("Version AoS, Time: %6.3f\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		RunBenchmark2(SIZE, data2);
	}
	timer.Stop();
	printf("Version SoA, Time: %6.3f\n", timer.GetElapsedTime());
	delete[] data;
	delete[] data2.x;
	delete[] data2.y;
	delete[] data2.z;
	delete[] data2.r2;
	return(0);
}
