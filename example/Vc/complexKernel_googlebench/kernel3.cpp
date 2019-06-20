#include <Vc/Vc>

using float_v = Vc::Vector<float>;
using sfloat_v = Vc::Scalar::Vector<float>;
auto constexpr S = float_v::Size;
auto constexpr K = S - 1;

template <typename T>
T core_kernel(T a, T b, T c) {
  auto d = c;
  auto cond = c < T(10.f);
  d(cond) = T(2.f) * a;
  return a * std::exp(d) + b;
}


void kernel3(float *a, float *b, float *c, float *res, int np) {
  int i = 0;
  // vectorizable part
  for (; i < np - K; i += S) {
    core_kernel(float_v(&a[i]), float_v(&b[i]), float_v(&c[i])).store(&res[i]);
  }
  // tail part
  for (; i < np; ++i) {
    core_kernel(sfloat_v(&a[i]), sfloat_v(&b[i]), sfloat_v(&c[i])).store(&res[i]);
  }
}

// scalar loop using the same kernel
void kernel4(float *a, float *b, float *c, float *res, int np) {
  for (int i = 0; i < np; ++i) {
    core_kernel(sfloat_v(&a[i]), sfloat_v(&b[i]), sfloat_v(&c[i])).store(&res[i]);
  }
}
