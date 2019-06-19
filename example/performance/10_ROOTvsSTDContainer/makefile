CXX=c++
# note that the C++ std should compatible with the one
# used by ROOT (and might have to be adapted)
CXXFLAGS=-std=c++11 -march=native -Wall -O2 -g
LDFLAGS:=$(shell root-config --libs)
INCDIR:=$(shell root-config --incdir)

benchmark:	benchmark.o timer.o
		$(CXX) -o $@ $^ $(LDFLAGS)

benchmark.o:	benchmark.cpp point.h makefile
		$(CXX) -I$(INCDIR) $(CXXFLAGS) -c $< -o $@

timer.o:	../base/timer.cpp ../base/timer.h makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

run:		benchmark
		@./benchmark
