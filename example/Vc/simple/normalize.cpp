#include <cmath>
#include <iostream>

void normalize(float& x, float& y, float& z);

int main()
{
  float x=2, y=3, z=-.5;

  normalize(x, y, z);

  std::cout << "normalized vector: [" << x << ", " << y << ", " << z << "]\n";

  return 1;
}

void normalize(float& x, float& y, float& z)
{
  const float d = std::sqrt(x * x + y * y + z * z);
  x /= d;
  y /= d;
  z /= d;
}

