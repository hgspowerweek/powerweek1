cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(myproject)
set(CMAKE_CXX_STANDARD 17)
find_package(ROOT REQUIRED)
include_directories(${ROOT_INCLUDE_DIRS})

# to get the ROOT_GENERATE_DICTIONARY Macro
include(${ROOT_USE_FILE})

# make the dictionary for Foo
ROOT_GENERATE_DICTIONARY(G__Foo Foo.h LINKDEF LinkDef.h)

# create shared lib containing Foo stuff including the dictionary symbols
add_library(Foo SHARED G__Foo.cxx Foo.cxx)
target_link_libraries(Foo ${ROOT_LIBRARIES})

#---Create the main program using the library
add_executable(main.exe main.cxx)
# link against ROOT and Foo
target_link_libraries(main.exe Foo  ${ROOT_LIBRARIES})
