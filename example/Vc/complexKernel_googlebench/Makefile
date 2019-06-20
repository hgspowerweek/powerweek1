VC_ROOT=/usr/local
CXXFLAGS=-I${VC_ROOT}/include -O2 -march=native -std=c++14


LDFLAGS=-L${VC_ROOT}/lib -lVc -lbenchmark -lpthread

TARGET=main
OBJS=main.o kernel1.o kernel2.o kernel3.o

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDFLAGS) -o $@

clean:
	@rm -f *.o $(TARGET)
