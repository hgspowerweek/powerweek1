cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(myproject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

#---Create the main program
add_executable(main.exe main.cxx)

