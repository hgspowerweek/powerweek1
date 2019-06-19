CXX=c++
CXXFLAGS=-Wall -O0 -g -ggdb
LDFLAGS=

all: program floatCompare minimal

program:	main.o
		$(CXX) $(LDFLAGS) -o $@ $^

main.o:		main.cpp makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@

floatCompare: floatCompare.o
		$(CXX) $(LDFLAGS) -o $@ $^

floatCompare.o: floatCompare.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

minimal: minimal.o
		 $(CXX) $(LDFLAGS) -o $@ $^

minimal.o: minimal.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm *.o minimal floatCompare program
