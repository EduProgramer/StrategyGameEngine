cmake_minimum_required (VERSION 3.6)
project (SGE)

#output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SGE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SGE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SGE)

#Compilers
if (CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

  if (ENABLE_COVERAGE)
    add_compile_options(--coverage -O0)
  endif()
endif()

#Enable all warnings
if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#sources
add_subdirectory (src)
