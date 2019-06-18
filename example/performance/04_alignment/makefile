CXX=c++
CXXFLAGS=-march=native -Wall -O3 -fno-tree-vectorize -g
LDFLAGS=

build:		benchmark benchmark-vec benchmark-unaligned benchmark-vec-unaligned

benchmark:	driver.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

benchmark-vec:	driver.o bench-vec.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

benchmark-unaligned:	driver-unaligned.o bench.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

benchmark-vec-unaligned:	driver-unaligned.o bench-vec.o timer.o
		$(CXX) $(LDFLAGS) -o $@ $^

driver.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -DOFFSET=0 -c $< -o $@

driver-unaligned.o:	driver.cpp ../base/timer.h bench.h makefile
		$(CXX) $(CXXFLAGS) -DOFFSET=2 -c $< -o $@

bench.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

bench-vec.o:	bench.cpp bench.h makefile
		$(CXX) $(CXXFLAGS) -ftree-vectorize -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark benchmark-vec benchmark-unaligned benchmark-vec-unaligned
		@echo Normal
		@./benchmark
		@echo Auto Vectorization
		@./benchmark-vec
		@echo Normal unaligned
		@./benchmark-unaligned
		@echo Auto Vectorization unaligned
		@./benchmark-vec-unaligned
