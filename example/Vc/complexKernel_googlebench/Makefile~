
#CXXFLAGS=-I${VC_ROOT}/include -O2 -march=native -fabi-version=6 -std=c++14 (for gcc)
CXXFLAGS=-I${VC_ROOT}/include -O2 -march=native -std=c++14

LDFLAGS=-L${VC_ROOT}/lib -lVc

TARGET=main
OBJS=main.o kernel1.o kernel2.o kernel3.o

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDFLAGS) -o $@

clean:
	@rm -f *.o $(TARGET)
