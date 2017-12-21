cmake_minimum_required(VERSION 3.1)

# Project's name
project(SGE)

# C++ standard
set (CMAKE_CXX_STANDARD 14)
# output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SGE)

#TODO compilation with profile
#TODO add sanitizers to debug flags
#TODO setup clang

# source
  # add production and test c++ files
  file(GLOB_RECURSE TEST_SRCS "./src/*.cpp")
  file(GLOB_RECURSE TEST_HDRS "./src/*.hpp")
  # remove production main
  list(REMOVE_ITEM TEST_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/./src/production/main.cpp")
  # add production c++ files
  file(GLOB_RECURSE SRCS "./src/production/*.cpp")
  file(GLOB_RECURSE HDRS "./src/production/*.hpp")


# specify targets
  add_executable(SGE_Debug ${HDRS} ${SRCS})
  add_executable(SGE_Release ${HDRS} ${SRCS})
  # Tests
  add_executable(SGE_Tests ${TEST_HDRS} ${TEST_SRCS})


# specify includes
set(SRC_ABSTRACT "./src/production/abstract")
set(SRC_CONCRETE "./src/production/concrete")
set(SRC_TEST "./src/tests")

set(INCLUDES
  "${SRC_ABSTRACT}/module"
  "${SRC_ABSTRACT}/platform"
  "${SRC_ABSTRACT}/platform/DrawManager"
  "${SRC_ABSTRACT}/platform/EventsManager"
  "${SRC_ABSTRACT}/platform/resources"
  "${SRC_ABSTRACT}/platform/Repository"
  "${SRC_ABSTRACT}/platform/SoundBox"
  "${SRC_ABSTRACT}/platform/StateMachine"

  "${SRC_CONCRETE}/module"
  "${SRC_CONCRETE}/module/GameModule"
  "${SRC_CONCRETE}/module/GUIModule"
  "${SRC_CONCRETE}/module/GameModule/logic"
  "${SRC_CONCRETE}/module/GUIModule/logic"
  "${SRC_CONCRETE}/platform"
  "${SRC_CONCRETE}/platform/DrawManager"
  "${SRC_CONCRETE}/platform/EventsManager"
  "${SRC_CONCRETE}/platform/resources"
  "${SRC_CONCRETE}/platform/Repository"
  "${SRC_CONCRETE}/platform/SoundBox"
  "${SRC_CONCRETE}/platform/StateMachine"
)

target_include_directories(SGE_Release PRIVATE ${INCLUDES} )
target_include_directories(SGE_Debug PRIVATE ${INCLUDES} )

set(TEST_INCLUDES ${GTEST_INCLUDE_DIRS}
  "${SRC_TEST}/module"
  "${SRC_TEST}/module/GameModule"
  "${SRC_TEST}/module/GUIModule"
  "${SRC_TEST}/module/GameModule/logic"
  "${SRC_TEST}/module/GUIModule/logic"
  "${SRC_TEST}/platform"
  "${SRC_TEST}/platform/DrawManager"
  "${SRC_TEST}/platform/EventsManager"
  "${SRC_TEST}/platform/resources"
  "${SRC_TEST}/platform/Repository"
  "${SRC_TEST}/platform/SoundBox"
  "${SRC_TEST}/platform/StateMachine"
)

target_include_directories(SGE_Tests BEFORE PRIVATE ${INCLUDES} ${TEST_INCLUDES})

# Define standard compiler flags
SET(GCC_STANDARD_FLAGS " -std=c++14 ")
SET(GCC_WARRNINGS_FLAGS " -Wall -Werror -Wextra -Wshadow -Wunused -pedantic -pedantic-errors ")

SET(GCC_DEBUG_FLAGS "${GCC_WARRNINGS_FLAGS} ${GCC_STANDARD_FLAGS} -g -O0 -fsanitize=return -fsanitize=signed-integer-overflow -fsanitize=pointer-compare -fsanitize=bounds -fsanitize=thread -fsanitize=leak -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls ASAN_OPTIONS=check_initialization_order=1 ASAN_OPTIONS=detect_leaks=1")

SET(GCC_RELEASE_FLAGS "${GCC_WARRNINGS_FLAGS} ${GCC_STANDARD_FLAGS} -O3")
# TODO add test coverage
SET(GCC_TEST_FLAGS "${GCC_DEBUG_FLAGS}")

# Release
target_compile_options(SGE_Release BEFORE PRIVATE ${GCC_RELEASE_FLAGS})

# Debug
target_compile_options(SGE_Debug BEFORE PRIVATE ${GCC_DEBUG_FLAGS})

# Tests
target_compile_options(SGE_Tests BEFORE PRIVATE ${GCC_TEST_FLAGS})
find_package(GTest)
target_link_libraries(SGE_Tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
