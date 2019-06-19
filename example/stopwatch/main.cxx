#include "stopwatch.h"
#include <cmath>
#include <iostream>

__attribute__((noinline)) 
double kernel(double  v) {
  return std::exp(v)*std::sin(v);
}

int main() {
  // use stopwatch like this to measure time taken by some kernel
  {
    precise_stopwatch watch; // gets initialized and started automatically
    volatile double x = kernel(1.); // volatile to prevent optimizing this away
    std::cerr << "Result " << x << " ; Computation took " << watch.elapsed_time<unsigned int, std::chrono::nanoseconds>() << " nano seconds \n";
  }
  return 0;
}
