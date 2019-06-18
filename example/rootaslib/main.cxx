#include <TRandom3.h> // include a ROOT random number generator 
#include <iostream>

int main() {
  TRandom3 generator;
  // get a poissonian distributed random number around 5
  std::cout << generator.Poisson(5) << std::endl;
  return 0;
}
