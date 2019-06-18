CXX       = /usr/bin/g++
CXXFLAGS  = -Wall -Wextra -Weffc++ -Wconversion -Wshadow -g -std=c++11
LDFLAGS   = -lboost_program_options

#-L/usr/lib/x86_64-linux-gnu
OBJ     = main.o

po: $(OBJ)
	$(CXX) -o po $(OBJ) $(LDFLAGS)

clean:
	@rm -f po $(OBJ)
