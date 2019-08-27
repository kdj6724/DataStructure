#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(dfs)

# Configuration
#

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
	include
)

add_executable(dfs
  src/main.cpp
)

TARGET_LINK_LIBRARIES(dfs
)
