#ifndef BENCH_H
#define BENCH_H

struct position
{
	float x, sigmax, y, sigmay, z, sigmaz, r2;
};

struct position_soa
{
	float *x, *sigmax, *y, *sigmay, *z, *sigmaz, *r2;
};

void RunBenchmark(long long int param, position* __restrict data);
void RunBenchmark2(long long int param, position_soa& __restrict data);

#endif
