CXX       = /usr/bin/g++
ARCHIVER  = ar cr
CXXFLAGS  = -Wall -Wextra -Weffc++ -Wconversion -Wshadow -g -fPIC
SOFLAGS   = -shared
SAFLAGS   = -static
LDFLAGS   = -L. -lHello

OBJ     = hello_fn.o main.o

LIB_DYN  = libHello.so
LIB_STAT = libHello.a

hello_dynamic: $(OBJ) $(LIB_DYN)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

hello_static: $(OBJ) $(LIB_STAT)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

main.o: main.cpp hello_fn.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)
	@echo bla

$(LIB_DYN): hello_fn.o
	$(CXX) -o $@ $(SOFLAGS) $^

$(LIB_STAT): hello_fn.o
	$(ARCHIVER) $@ $^

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo explicit

clean:
	@rm -f ${OBJ} hello_dynamic hello_static $(LIB_DYN) $(LIB_STAT)
