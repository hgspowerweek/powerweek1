cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(myproject)
set(CMAKE_CXX_STANDARD 17)
find_package(ROOT REQUIRED)
include_directories(${ROOT_INCLUDE_DIRS})

# to get the ROOT_GENERATE_DICTIONARY Macro
include(${ROOT_USE_FILE})

# make the dictionary for Position
ROOT_GENERATE_DICTIONARY(G__Position Position.h LINKDEF LinkDef.h)

# create shared lib containing Position stuff including the dictionary symbols
add_library(Position SHARED G__Position.cxx Position.cxx)
target_link_libraries(Position ${ROOT_LIBRARIES})

#---Create the main program using the library
add_executable(main.exe main.cxx)
# link against ROOT and Position
target_link_libraries(main.exe Position  ${ROOT_LIBRARIES})
