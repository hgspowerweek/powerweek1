CXX=g++
CXXFLAGS:=-g -Wall -I. -std=c++17 -O2 -I/usr/include/benchmark -fno-omit-frame-pointer -fopenmp
LIBS = -lbenchmark -lpthread -L. -ltbb

OBJECTS:=test.o
SRCS:=test.cxx

all: test 
	./test

test: $(SRCS) test.o 
	$(CXX) -o  $@  $< $(CXXFLAGS) $(LIBS)

%.o: %.cxx 
	$(CXX) $(CXXFLAGS) -c $< 
%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< 

clean: 
	rm -f *.o *~ *.so test

.PHONY: clean
