CXX=c++
CXXFLAGS=-march=native -Wall -O3 -g -fopenmp
LDFLAGS=-fopenmp

benchmark:	driver.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

timer.o:	timer.cpp timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
