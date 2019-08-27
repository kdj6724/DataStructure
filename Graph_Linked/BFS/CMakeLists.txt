#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(bfs)

# Configuration
#

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
	include
)

add_executable(bfs
  src/main.cpp
)

TARGET_LINK_LIBRARIES(bfs
)
