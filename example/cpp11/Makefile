CXXFLAGS=-std=c++14 -W -Wall
ROOTCXXFLAGS  = -I$(shell root-config --incdir) -std=c++14
ROOTLDFLAGS   = $(shell root-config --libs) -lEG


CPPS_WORK = null_ptr.cpp  range_based.cpp enum1.cpp enum2.cpp enum_strong.cpp
TARGETS_WORK = $(CPPS_WORK:%.cpp=%)

all: $(TARGETS_WORK) Makefile

null_ptr_fail: Makefile

#enum_fail: Makefile

range_based_root: range_based_root.cpp Makefile
	$(CXX) $(CXXFLAGS) $(ROOTCXXFLAGS) $< $(ROOTLDFLAGS) -o $@ 


clean:
	rm $(TARGETS)
