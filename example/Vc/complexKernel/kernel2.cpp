#include <Vc/Vc>

using float_v = Vc::Vector<float>;

void kernel2(float *a, float *b, float *c, float *res, int np) 
{
  for (int i = 0; i < np; i += float_v::Size) {
    float_v a_v(&a[i]);
    float_v c_v(&c[i]);
    auto d_v = c_v;
    auto cond = (c_v < 10.f);
    d_v(cond) = 2.f * a_v;
    auto r_v = a_v * std::exp(d_v) + float_v(&b[i]);
    r_v.store(&res[i]);
  }
}

