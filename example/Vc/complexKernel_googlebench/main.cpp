#include <iomanip>
#include <benchmark/benchmark.h> // for google benchmark 

void kernel1(float *a, float *b, float *c, float *res, int np);
void kernel2(float *a, float *b, float *c, float *res, int np);
void kernel3(float *a, float *b, float *c, float *res, int np);
void kernel4(float *a, float *b, float *c, float *res, int np);


// some global data container used by all benchmarks
const int np=50000;
float a[np];
float b[np];
float c[np];
float res1[np];

void initData() {
  for (int i=0; i<np; ++i) {
    a[i]=i/float(np);
    b[i]=2*i;
    c[i]=3;
  }
}


static void benchmarkKernel1_Original(benchmark::State& state) {
  initData();
  for (auto tmp : state) {
    kernel1(a, b, c, res1, np);
    benchmark::DoNotOptimize(res1);
  }
}
BENCHMARK(benchmarkKernel1_Original);

static void benchmarkKernel3_SIMD(benchmark::State& state) {
  initData();
  for (auto tmp : state) {
    kernel3(a, b, c, res1, np);
    benchmark::DoNotOptimize(res1);
  }
}
BENCHMARK(benchmarkKernel3_SIMD);

static void benchmarkKernel4_Scalar(benchmark::State& state) {
  initData();
  for (auto tmp : state) {
    kernel4(a, b, c, res1, np);
    benchmark::DoNotOptimize(res1);
  }
}
BENCHMARK(benchmarkKernel4_Scalar);


BENCHMARK_MAIN();
