#ifndef BENCH_H
#define BENCH_H

int RunBenchmark(int param, int* __restrict data);
int RunBenchmark8(int param, int* __restrict data);
int RunBenchmark16(int param, int* __restrict data);
int RunBenchmark64(int param, int* __restrict data);
int RunBenchmark256(int param, int* __restrict data);

#endif
