#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bench.h"
#include "intermediate.h"
#include "../base/timer.h"

#define SIZE (1024)
#define ITER (1024 * 1024)

class_virtual c_virt;
class_derived c_der;

int main(int argc, char** argv)
{
	HighResTimer timer;
	int* data = new int[SIZE];
	memset(data, 0, SIZE * sizeof(data[0]));
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		loop_inline(SIZE, data);
	}
	timer.Stop();
	printf("Version Inline, Time: %6.3f\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		loop_basic(SIZE, data);
	}
	timer.Stop();
	printf("Version Basic, Time: %6.3f\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		loop_virtual2(SIZE, data);
	}
	timer.Stop();
	printf("Version Virtual, Time: %6.3f\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	for (int i = 0;i < ITER;i++)
	{
		loop_virtual(&c_virt, SIZE, data);
	}
	timer.Stop();
	printf("Version Virtual with class pointer, Time: %6.3f\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	class_virtual* cls[4] = {&c_virt, &c_der, &c_virt, &c_der};
	for (int i = 0;i < ITER;i++)
	{
		loop_virtual_multiple(cls, SIZE, data);
	}
	timer.Stop();
	printf("Version Multiple Different Virual Calls, Time: %6.3f\n", timer.GetElapsedTime());
	timer.Reset();
	timer.Start();
	class_virtual* cls2[4] = {&c_virt, &c_virt, &c_virt, &c_virt};
	for (int i = 0;i < ITER;i++)
	{
		loop_virtual_multiple(cls2, SIZE, data);
	}
	timer.Stop();
	printf("Version Multiple Identical Virual Calls, Time: %6.3f\n", timer.GetElapsedTime());
	delete[] data;
	return(0);
}
