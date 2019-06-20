#include <cmath>
#include <iostream>
#include <Vc/Vc>

using Vc::float_v;

void normalize(float_v& x, float_v& y, float_v& z);

int main()
{
  float_v x(2.f), y(3.f), z(-.5f);

  normalize(x, y, z);

  for (int i=0; i<float_v::Size; ++i) {
    std::cout << "normalized vector " << i << ": [" << x[i] << ", " << y[i] << ", " << z[i] << "]\n";
  }

  return 1;
}

void normalize(float_v& x, float_v& y, float_v& z)
{
  const float_v d = std::sqrt(x * x + y * y + z * z);
  x /= d;
  y /= d;
  z /= d;
}


