CXX=c++
CXXFLAGS=-march=native -Wall -O2 -g
LDFLAGS=

benchmark:	driver.o bench.o bench2.cpp intermediate.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp ../base/timer.h intermediate.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench2.o:	bench2.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

intermediate.o:	intermediate.cpp bench.h intermediate.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
