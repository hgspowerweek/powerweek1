CXX=c++
CXXFLAGS=-march=native -Wall -O3 -g
LDFLAGS=

build:		benchmark benchmark-lto

benchmark:	driver.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

benchmark-lto:	driver-lto.o bench-lto.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^ -flto

driver.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

driver-lto.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@ -flto

bench-lto.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@ -flto


run:		benchmark benchmark-lto
		@echo Normal
		@./benchmark
		@echo LTO
		@./benchmark-lto
