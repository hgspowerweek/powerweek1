CXX=c++
CXXFLAGS=-march=native -Wall -O0 -g -std=c++11
LDFLAGS=

benchmark:	driver.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
