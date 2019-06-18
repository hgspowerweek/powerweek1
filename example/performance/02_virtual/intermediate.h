#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H
#include "bench.h"

void loop_virtual(class_virtual* cls, int param, int* data);
void loop_virtual_multiple(class_virtual** cls, int param, int* data);
void loop_virtual2(int param, int* data);
void loop_basic(int param, int* data);
void loop_inline(int param, int* data);

#endif
