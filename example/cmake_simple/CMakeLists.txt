cmake_minimum_required(VERSION 3.9)
project(MyPowerProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "Using C++${CMAKE_CXX_STANDARD}")

add_executable(testExe test.cc)

add_library(power power.cc)

add_executable(main main.cc)
target_link_libraries(main power)

set_target_properties(power PROPERTIES LINK_FLAGS "-Wl,--as-needed")
set_target_properties(power PROPERTIES LINK_FLAGS "-Wl,--no-undefined")

set(SOURCES s1.cc s2.cc s3.cc)
add_library(s ${SOURCES})

set(EXECUTABLES e1 e2 e3)
foreach(EXE ${EXECUTABLES})
  add_executable(${EXE} ${EXE}.cc)
  target_link_libraries(${EXE} power)
endforeach()

find_package(ROOT)
if(ROOT_FOUND)
  include(${ROOT_USE_FILE})
  message(STATUS "Using ROOT: ${ROOT_VERSION} <${ROOT_CONFIG}>")
  target_compile_definitions(power PUBLIC "-DUSE_ROOT")
  target_include_directories(power PRIVATE ${ROOT_INCLUDE_DIRS})
  target_include_directories(power PRIVATE .)
  ROOT_GENERATE_DICTIONARY(G__Power ${CMAKE_CURRENT_SOURCE_DIR}/power.h LINKDEF LinkDef.h)
  target_sources(power PRIVATE power_rooted.cc G__Power)
  target_link_libraries(power ROOT::Core ROOT::Gui ROOT::Tree)
endif(ROOT_FOUND)

# by default build optimized code with debug symbols
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RELWITHDEBINFO)
endif()

set(CMAKE_ALLOWED_BUILD_TYPES DEBUG RELEASE RELWITHDEBINFO)

if(NOT CMAKE_BUILD_TYPE IN_LIST CMAKE_ALLOWED_BUILD_TYPES)
  message(FATAL_ERROR "Invalid build type ${CMAKE_BUILD_TYPE}. Use one of: ${CMAKE_ALLOWED_BUILD_TYPES}.")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb -DDEBUG -D__DEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -ftree-vectorize -ffast-math -DNODEBUG")
message(STATUS "Using CXX flags for ${CMAKE_BUILD_TYPE}: ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}}")

install(TARGETS main power
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )

enable_testing()
add_test(NAME MyPowerTest COMMAND main)
