#
CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
#
PROJECT(pq)
# Configuration
#
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
SET(CMAKE_CXX_FLAGS "-std=c++11 -g")
set(CMAKE_SOURCE src/main.cpp)

include_directories(
	${PROJECT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE})
