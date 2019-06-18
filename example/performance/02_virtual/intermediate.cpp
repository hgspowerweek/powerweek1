#include "intermediate.h"
#include "bench.h"

class_virtual c_virt2;
class_basic c_basic;
class_inline c_inline;

void loop_virtual(class_virtual* cls, int param, int* data)
{
	for (int i = 0;i < param;i++) cls->foo(&data[i]);
}

void loop_virtual2(int param, int* data)
{
	for (int i = 0;i < param;i++) c_virt2.foo(&data[i]);
}

void loop_basic(int param, int* data)
{
	for (int i = 0;i < param;i++) c_basic.foo(&data[i]);
}

void loop_inline(int param, int* data)
{
	for (int i = 0;i < param;i++) c_inline.foo(&data[i]);
}

void loop_virtual_multiple(class_virtual** cls, int param, int* data)
{
	for (int i = 0;i < param;i++) cls[i & 3]->foo(&data[i]);
}
