CXX       = /usr/bin/g++
#flags for the actual compilation
CXXFLAGS  = -fPIC -Wall -Wextra -Wconversion -Wshadow -Weffc++ -I$(shell root-config --cflags)
#flags for the linker
LDFLAGS   = $(shell root-config --libs)
#flags used for the linking of the shared object library
SOFLAGS   = -fPIC -shared

#user definitions concerning the procjet
PROJ    = Sim
OBJ     = event.o particle.o 
MAIN    = main.o


HDR     = $(OBJ:%.o=%.h)
DHDR    = $(PROJ)LinkDef.h
MAINCPP = $(MAIN:%.o=%.cpp)

$(PROJ): $(MAIN) lib$(PROJ).so 
	$(CXX) -o $@ $^ $(LDFLAGS) -L. -l$(PROJ)

lib$(PROJ).so: $(OBJ) G__$(PROJ).o
	$(CXX) $(SOFLAGS) $(LDFLAGS) $^ -o $@

$(MAIN): $(MAINCPP) $(HDR)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

# root dictionary generation
G__$(PROJ).cpp: $(HDR) $(DHDR)
	@echo "Generating dictionary ..."
	rootcint -f $@ -c $(CXXFLAGS) $^
clean:
	@rm -f $(OBJ) $(MAIN) G__*  lib$(PROJ).so $(PROJ) *_ACLiC_dict_*

