#include <iostream>
#include <omp.h>
#include <unistd.h>
#include <math.h>
#include <chrono>

double f(const double x)
{
  return x*x;
}

#pragma omp declare simd
double g(const double x)
{
  return x*x;
}

int main()
{
  constexpr int n = 1000000;
  int x[n], y[n];

  auto ts = std::chrono::high_resolution_clock::now();
#pragma omp parallel for
  for (int i = 0; i < n; ++i)
    y[i] = x[i] * x[i];
  auto te = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(te - ts);
  std::cout << "duration: " << time_span.count() << " seconds" << std::endl;

  ts = std::chrono::high_resolution_clock::now();
#pragma omp parallel for simd
  for (int i = 0; i < n; ++i)
    y[i] = x[i] * x[i];
  te = std::chrono::high_resolution_clock::now();
  time_span = std::chrono::duration_cast<std::chrono::duration<double>>(te - ts);
  std::cout << "duration: " << time_span.count() << " seconds" << std::endl;

  ts = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; ++i)
    y[i] = f(x[i]);
  te = std::chrono::high_resolution_clock::now();
  time_span = std::chrono::duration_cast<std::chrono::duration<double>>(te - ts);
  std::cout << "duration: " << time_span.count() << " seconds" << std::endl;

  ts = std::chrono::high_resolution_clock::now();
#pragma omp simd
  for (int i = 0; i < n; ++i)
    y[i] = g(x[i]);
  te = std::chrono::high_resolution_clock::now();
  time_span = std::chrono::duration_cast<std::chrono::duration<double>>(te - ts);
  std::cout << "duration: " << time_span.count() << " seconds" << std::endl;
  ts = std::chrono::high_resolution_clock::now();

#pragma omp parallel for simd
  for (int i = 0; i < n; ++i)
    y[i] = g(x[i]);
  te = std::chrono::high_resolution_clock::now();
  time_span = std::chrono::duration_cast<std::chrono::duration<double>>(te - ts);
  std::cout << "duration: " << time_span.count() << " seconds" << std::endl;
}
