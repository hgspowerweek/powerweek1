#include "bench.h"
#include <math.h>

void class_virtual::foo(int* ptr) {*ptr = 1;}
void class_basic::foo(int* ptr) {
    *ptr += 1;
    *ptr *= 3;
    *ptr = sqrt(*ptr);
    *ptr = 2. / *ptr;
}
