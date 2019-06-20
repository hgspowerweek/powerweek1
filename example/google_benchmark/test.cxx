#include <benchmark/benchmark.h>
#include <math.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include <execution>
#include <omp.h>
#include <atomic>
#include <cstdio>
#include <cmath>
#include <mutex>

using namespace std;

auto complexFunction = [](auto x) {
using std::sqrt;
      return std::log(std::sin(x)/std::pow(x/3.f, 2.5f) - std::atan(25.f/x) + sqrt(sqrt(sqrt(sqrt(x)))));
};

static void complexFunctionSeqFloat(benchmark::State& state) {
  vector<float> data(100000);
  iota(data.begin(), data.end(), decltype(data)::value_type(0.));

  for (auto tmp : state) {
    using std::sqrt;

    for_each(data.begin(), data.end(), [](auto& x) {
      x = complexFunction(x);
    });

    auto sum = std::accumulate(data.begin(), data.end(), decltype(data)::value_type(0));
    benchmark::DoNotOptimize(sum);
  
  }
}
BENCHMARK(complexFunctionSeqFloat);

static void complexFunctionSeqDouble(benchmark::State& state) {
  vector<double> data(100000);
  iota(data.begin(), data.end(), decltype(data)::value_type(0.));

  for (auto tmp : state) {
    using std::sqrt;

    for_each(data.begin(), data.end(), [](auto& x) {
      x = complexFunction(x);
    });

    auto sum = std::accumulate(data.begin(), data.end(), decltype(data)::value_type(0));
    benchmark::DoNotOptimize(sum);
  
  }
}
BENCHMARK(complexFunctionSeqDouble);

static void complexFunctionPar(benchmark::State& state) {
  vector<float> data(state.range(0.));
  iota(data.begin(), data.end(), decltype(data)::value_type(0.));

  for (auto _ : state) {
  
    for_each(execution::par, data.begin(), data.end(), [](auto& x) {
      x = complexFunction(x);
    });

    auto sum = std::accumulate(data.begin(), data.end(), decltype(data)::value_type(0));
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(complexFunctionPar)->RangeMultiplier(64)->Range(2,2<<18);

static void complexFunctionOMP(benchmark::State& state) {
  vector<float> data(state.range(0.));
  iota(data.begin(), data.end(), decltype(data)::value_type(0.));

  for (auto tmp : state) {

    #pragma omp parallel for
    for (auto& x:data) {
      x = complexFunction(x);
    };
    auto sum = std::accumulate(data.begin(), data.end(), decltype(data)::value_type(0));
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(complexFunctionOMP)->RangeMultiplier(64)->Range(2,2<<18);

static void complexFunctionParSync(benchmark::State& state) {
  vector<float> data(state.range(0.));
  iota(data.begin(), data.end(), decltype(data)::value_type(0.));


  for (auto _ : state) {
    float sum{0.};
    std::mutex mutex;
    for_each(execution::par, data.begin(), data.end(), [&](auto& x) {
      x = complexFunction(x);
      std::lock_guard<std::mutex> guard(mutex);
      sum+=x;
    });

    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(complexFunctionParSync)->RangeMultiplier(64)->Range(2,2<<18);

static void complexFunctionOMPSync(benchmark::State& state) {
  vector<float> data(state.range(0.));
  iota(data.begin(), data.end(), decltype(data)::value_type(0.));

  for (auto tmp : state) {
    float sum{0.};
    std::mutex mutex;
    #pragma omp parallel for
    for (auto& x:data) {
      x = complexFunction(x);
      std::lock_guard<std::mutex> guard(mutex);
      sum+=x;
    };
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(complexFunctionOMPSync)->RangeMultiplier(64)->Range(2,2<<18);


BENCHMARK_MAIN();

