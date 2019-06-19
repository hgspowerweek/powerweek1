CXX=c++
CXXFLAGS=-march=native -Wall -O2 -g
LDFLAGS=

benchmark:	driver.o bench.o intermediate.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp intermediate.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

intermediate.o:	intermediate.cpp bench.h intermediate.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
