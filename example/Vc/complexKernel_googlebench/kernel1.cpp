#include <cmath>

void kernel1(float *a, float *b, float *c, float *res, int np) 
{

  for (int i = 0; i < np; ++i) {
    float d = (c[i] < 10.) ? c[i] : 2. * a[i];
    res[i] = a[i] * std::exp(d) + b[i];
  }

}
