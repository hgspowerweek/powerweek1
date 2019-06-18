cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(myproject)
set(CMAKE_CXX_STANDARD 17)
find_package(ROOT REQUIRED)
# add the dir where to find ROOT headers
include_directories(${ROOT_INCLUDE_DIRS})

#---Create the main program
add_executable(main.exe main.cxx)
# link against ROOT libs
target_link_libraries(main.exe ${ROOT_LIBRARIES})
