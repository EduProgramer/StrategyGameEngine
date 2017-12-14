cmake_minimum_required(VERSION 3.1)

# Project's name
project(SGE)

# C++ standard
set (CMAKE_CXX_STANDARD 14)

#TODO compilation switch test/profile/
#TODO add sanitizers to debug flags

message( "Build type: ${CMAKE_BUILD_TYPE}")

# Define standard compiler flags
SET(GCC_STANDARD_FLAGS " -std=c++14 ")
SET(GCC_WARRNINGS_FLAGS " -Wall -Werror -Wextra -Wshadow -Wunused -pedantic -pedantic-errors ")
SET(GCC_DEBUG_FLAGS "${GCC_WARRNINGS_FLAGS} ${GCC_STANDARD_FLAGS} -g -O0")
SET(GCC_RELASE_FLAGS "${GCC_WARRNINGS_FLAGS} ${GCC_STANDARD_FLAGS} -O3")
# TODO add test coverage
SET(GCC_TEST_FLAGS "${GCC_DEBUG_FLAGS}")

MARK_AS_ADVANCED(
    CMAKE_CXX_FLAGS_COVERAGE
    )

IF(NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE Relase
       CACHE STRING "Choose the type of build : None Relase Release RelWithDebInfo MinSizeRel Coverage."
       FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SGE)

# source
if(${CMAKE_BUILD_TYPE} STREQUAL "Test")
  # add production and test c++ files
  file(GLOB_RECURSE SRCS "./src/*.cpp")
  file(GLOB_RECURSE HDRS "./src/*.hpp")
  # remove production main
  list(REMOVE_ITEM SRCS "src/production/main.cpp")
else()
  # add production c++ files
  file(GLOB_RECURSE SRCS "./src/production/*.cpp")
  file(GLOB_RECURSE HDRS "./src/production/*.hpp")
endif()

message( "HEADERS: \n${HDRS}")
message( "SOURCE FILES: \n${SRCS}")

# specify executable
add_executable(SGE ${HDRS} ${SRCS})

# switch compile options
 if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
   add_compile_options(${GCC_DEBUG_FLAGS})
 elseif(${CMAKE_BUILD_TYPE} STREQUAL "Relase")
   add_compile_options(${GCC_RELASE_FLAGS})
 elseif(${CMAKE_BUILD_TYPE} STREQUAL "Test")
   add_compile_options(${GCC_TEST_FLAGS})
 else()
   message( FATAL_ERROR "Build type is not set" )
 endif()

message( "Building ${CMAKE_BUILD_TYPE} version of the application. flags: \n${GCC_RELASE_FLAGS}")

#compile ut
#add_subdirectory(unit_test)
