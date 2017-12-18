cmake_minimum_required(VERSION 3.1)

# Project's name
project(SGE)

# C++ standard
set (CMAKE_CXX_STANDARD 14)
# output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SGE)

#TODO compilation with profile
#TODO add sanitizers to debug flags

message( "Build type: ${CMAKE_BUILD_TYPE}")

# Define standard compiler flags
SET(GCC_STANDARD_FLAGS " -std=c++14 ")
SET(GCC_WARRNINGS_FLAGS " -Wall -Werror -Wextra -Wshadow -Wunused -pedantic -pedantic-errors ")
SET(GCC_DEBUG_FLAGS "${GCC_WARRNINGS_FLAGS} ${GCC_STANDARD_FLAGS} -g -O0 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls ASAN_OPTIONS=check_initialization_order=1 ASAN_OPTIONS=detect_leaks=1")
SET(GCC_RELEASE_FLAGS "${GCC_WARRNINGS_FLAGS} ${GCC_STANDARD_FLAGS} -O3")
# TODO add test coverage
SET(GCC_TEST_FLAGS "${GCC_DEBUG_FLAGS}")

MARK_AS_ADVANCED(
    CMAKE_CXX_FLAGS_COVERAGE
    )

IF(NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE Release
       CACHE STRING "Choose the type of build : None Release Debug Test."
       FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# source
if(${CMAKE_BUILD_TYPE} STREQUAL "Test")
  # find GTest framework
  find_package(GTest REQUIRED)
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

# specify executable
add_executable(SGE ${HDRS} ${SRCS})

# specify includes
set(SRC_ABSTRACT "./src/production/abstract")
set(SRC_CONCRETE "./src/production/concrete")
set(SRC_TEST "./src/tests")

target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/module")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform/DrawManager")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform/EventsManager")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform/resources")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform/Repository")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform/SoundBox")
target_include_directories(SGE PUBLIC "${SRC_ABSTRACT}/platform/StateMachine")

target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/module")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/module/GameModule")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/module/GUIModule")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/module/GameModule/logic")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/module/GUIModule/logic")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform/DrawManager")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform/EventsManager")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform/resources")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform/Repository")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform/SoundBox")
target_include_directories(SGE PUBLIC "${SRC_CONCRETE}/platform/StateMachine")

# if testing include GTest and tests
if(${CMAKE_BUILD_TYPE} STREQUAL "Test")
  target_include_directories(SGE PUBLIC ${GTEST_INCLUDE_DIRS})

  target_include_directories(SGE PUBLIC "${SRC_TEST}/module")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/module/GameModule")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/module/GUIModule")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/module/GameModule/logic")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/module/GUIModule/logic")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform/DrawManager")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform/EventsManager")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform/resources")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform/Repository")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform/SoundBox")
  target_include_directories(SGE PUBLIC "${SRC_TEST}/platform/StateMachine")
endif()

# switch compile options
 if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
   add_compile_options(${GCC_DEBUG_FLAGS})
   message("flags:${GCC_DEBUG_FLAGS}")
 elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
   add_compile_options(${GCC_RELEASE_FLAGS})
   message("flags:${GCC_RELEASE_FLAGS}")
 elseif(${CMAKE_BUILD_TYPE} STREQUAL "Test")
   add_compile_options(${GCC_TEST_FLAGS})
   message("flags:${GCC_TEST_FLAGS}")
 else()
   message( FATAL_ERROR "Build type is not set" )
 endif()

 message( "Building ${CMAKE_BUILD_TYPE} version of the application.")

# if testing link GTest
if(${CMAKE_BUILD_TYPE} STREQUAL "Test")
  target_link_libraries(SGE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
endif()
