#include <Vc/Vc>
#include <iostream>
#include <iomanip>
#include <chrono>
using Vc::float_v;

using std::nano;

using float_v = Vc::Vector<float>;

void kernel1(float *a, float *b, float *c, float *res, int np);
void kernel2(float *a, float *b, float *c, float *res, int np);
void kernel3(float *a, float *b, float *c, float *res, int np);
void kernel4(float *a, float *b, float *c, float *res, int np);

int main()
{
  std::cout << "Size of a float SIMD register: " << float_v::Size << std::endl;

  const int nIterations = 10000;

  const int np=50000;
  float a[np];
  float b[np];
  float c[np];
  for (int i=0; i<np; ++i) {
    a[i]=i/float(np);
    b[i]=2*i;
    c[i]=3;
  }

  float res1[np];
  float res2[np];
  float res3[np];
  float res4[np];


  {
    auto start = std::chrono::steady_clock::now();

    for (int i=0; i<nIterations; ++i)
      kernel1(a, b, c, res1, np);

    auto end = std::chrono::steady_clock::now();
    auto diff = end-start;

    std::cout << "kernel1: " << std::chrono::duration <double, nano> (diff).count() << " ns" << std::endl;
    std::cout << std::endl;
  }

  {
    auto start = std::chrono::steady_clock::now();

    for (int i=0; i<nIterations; ++i)
      kernel2(a, b, c, res2, np);

    auto end = std::chrono::steady_clock::now();
    auto diff = end-start;

    std::cout << "kernel2: " << std::chrono::duration <double, nano> (diff).count() << " ns" << std::endl;
    std::cout << std::endl;
  }

  {
    auto start = std::chrono::steady_clock::now();

    for (int i=0; i<nIterations; ++i)
      kernel3(a, b, c, res3, np);

    auto end = std::chrono::steady_clock::now();
    auto diff = end-start;

    std::cout << "kernel3: " << std::chrono::duration <double, nano> (diff).count() << " ns" << std::endl;
    std::cout << std::endl;
  }

  {
    auto start = std::chrono::steady_clock::now();

    for (int i=0; i<nIterations; ++i)
      kernel4(a, b, c, res4, np);

    auto end = std::chrono::steady_clock::now();
    auto diff = end-start;

    std::cout << "kernel4: " << std::chrono::duration <double, nano> (diff).count() << " ns" << std::endl;
    std::cout << std::endl;
  }
  


}
