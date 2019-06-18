CXX=c++
CXXFLAGS=-march=native -Wall -O3 -g -fno-tree-vectorize
LDFLAGS=

build:		benchmark benchmark_vec

benchmark:	driver.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

benchmark_vec:	driver.o bench_vec.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

bench_vec.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -ftree-vectorize -c $< -o $@

run:		build
		@echo "Normal"
		@./benchmark
		@echo "Auto-Vectorized"
		@./benchmark_vec

