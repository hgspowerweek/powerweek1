CXX=c++
CXXFLAGS=-march=native -Wall -O3 -g
LDFLAGS=

benchmark:	driver.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
