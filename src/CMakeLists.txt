add_subdirectory (include)

add_executable (sge main.cpp)

target_include_directories (sge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
