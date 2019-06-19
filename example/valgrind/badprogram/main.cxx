#include <cmath>
#include <iostream>
#include <vector>

// A program having few performance bugs
// Can you spot them directly or with valgrind/callgrind?
// It is in any case adviced to verify that the bugs are
// visible in callgrind


// some kernel returning the sum of cubes of elements in a vector
__attribute__((noinline)) 
double kernel(std::vector<double> const v) {
  double accum = 0.;
  for (auto &e : v) {
    accum += pow(e, 3);
  }
  return accum;
}

int main() {
  std::vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  double accum = 0.;
  // loop just to generate some work
  for (size_t i = 0; i < 10000; ++i) {
    accum += kernel(v);
  }

  std::cerr << "result " << accum << "\n";
  return 0;
}
