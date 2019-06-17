CXX       = /usr/bin/g++
CXXFLAGS  = -Wall -Wextra -Weffc++ -Wconversion -Wshadow -g
LDFLAGS   =

OBJ     = hello_fn.o main.o

split: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

main.o: main.cpp hello_fn.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)
	@echo bla

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo explicit

clean:
	@rm -f ${OBJ} split
