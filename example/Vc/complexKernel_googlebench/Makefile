
#CXXFLAGS=-I${VC_ROOT}/include -O2 -march=native -fabi-version=6 -std=c++14 (for gcc)
CXXFLAGS=-I${VC_ROOT}/include -I/usr/local/Cellar/google-benchmark/1.5.0/include/ -O2 -march=native -std=c++14


LDFLAGS=-L${VC_ROOT}/lib -lVc -L/usr/local/Cellar/google-benchmark/1.5.0/lib/ -lbenchmark

TARGET=main
OBJS=main.o kernel1.o kernel2.o kernel3.o

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDFLAGS) -o $@

clean:
	@rm -f *.o $(TARGET)
