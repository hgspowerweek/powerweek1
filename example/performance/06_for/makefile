CXX=c++
CXXFLAGS=-march=native -Wall -O3 -g
LDFLAGS=

benchmark:	driver.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
