cmake_minimum_required(VERSION 3.10)
project(MyStringTests)

set(CMAKE_CXX_STANDARD 11)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files
set(SOURCE_FILES myString.cpp test.cpp)

# Create the test executable
add_executable(runTests ${SOURCE_FILES})

# Link against Google Test and pthread
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
