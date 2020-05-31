# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("cmake-conan-example")

# Install cmake-conan script.
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

# Launch conan install for required packages.
conan_cmake_run(REQUIRES poco/1.9.4
                BASIC_SETUP)

# Here is where to add includes for libs provided through Conan. 
# Do not forget to also link to these when making target executable or lib.
# See also the other CMakeList.txt in the subdirectory of this project.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Include sub-projects.
add_subdirectory ("cmake-conan-example")