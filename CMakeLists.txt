cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HuffmanEncoder)

# Specify the C++ standard (C++17 is great for this kind of project)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where to find your header files
include_directories("Header Files")

# Find all your source files
file(GLOB SOURCES "Cpp Files/*.cpp")

# Create the executable
add_executable(HuffmanEncoder ${SOURCES})