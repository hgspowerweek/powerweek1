MAIN=example_template
SRCS=$(shell ls *.cc)
HDR=$(foreach h, $(SRCS:.cc=.h), $(shell test -f $h && ls $h))

all: $(MAIN) vector

$(MAIN): main.o $(SRCS:.cc=.o) $(HDR)
	$(CXX) $(LDFLAGS) -o $@ $<

vector: vector.o $(SRCS:.cc=.o) $(HDR)
	$(CXX) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(MAIN) $(SRCS:.cc=.o) *~
