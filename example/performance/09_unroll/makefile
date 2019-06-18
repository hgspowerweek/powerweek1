CXX=c++
CXXFLAGS=-march=native -Wall -O3 -fno-unroll-loops -g
LDFLAGS=

build:		benchmark benchmark-unroll

benchmark:	driver.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

benchmark-unroll:	driver.o bench-unroll.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^ -flto

driver.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench-unroll.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@ -funroll-loops

run:		benchmark benchmark-unroll
		@echo Normal
		@./benchmark
		@echo -funroll-loops
		@./benchmark-unroll
