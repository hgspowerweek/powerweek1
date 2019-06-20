#include <cmath>
#include <iostream>
#include <Vc/Vc>

using Vc::float_v;

template <typename T>
void normalize(T& x, T& y, T& z);

int main()
{
  float x=2, y=3, z=-.5;
  float_v xv(2.f), yv(3.f), zv(-.5f);

  normalize(x, y, z);
  std::cout << "normalized vector: [" << x << ", " << y << ", " << z << "]\n";

  normalize(xv, yv, zv);
  for (int i=0; i<float_v::Size; ++i) {
    std::cout << "normalized SIMD vector " << i << ": [" << xv[i] << ", " << yv[i] << ", " << zv[i] << "]\n";
  }

  return 1;
}

template <typename T>
void normalize(T& x, T& y, T& z)
{
  const T d = std::sqrt(x * x + y * y + z * z);
  x /= d;
  y /= d;
  z /= d;
}

