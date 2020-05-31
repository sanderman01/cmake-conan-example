# CMakeList.txt : CMake project for cmake-example, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (example "example.cpp" "example.h")
target_link_libraries(example ${CONAN_LIBS})
# TODO: Add tests and install targets if needed.
