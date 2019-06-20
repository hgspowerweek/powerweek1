#CXXFLAGS=-O2 -march=native -fabi-version=6 -std=c++14
CXXFLAGS=-O2 -fabi-version=6 -std=c++14
LDFLAGS=-lVc

ifdef VC_ROOT
CXXFLAGS+=-I${VC_ROOT}/include
LDFLAGS+=-L${VC_ROOT}/lib
endif

TARGETS=normalize normalize_vc normalize_template normalize_template_opt polar polar_vc masks

all: $(TARGETS)

%: %.cpp
	$(CXX) $^ $(LDFLAGS) $(CXXFLAGS) -o $@

clean:
	@rm -f *.o $(TARGETS)
