cmake_minimum_required(VERSION 3.22)

project(SortingVis VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(SORT_LIBRARY sort)
set(EXECUTABLE_NAME sorter)

option(ENABLE_DEBUG "Enable debugging" OFF)

if(ENABLE_DEBUG)
  message(STATUS "Debugging is ENABLED")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
  add_definitions(-DDEBUG)
else()
  message(STATUS "Debugging is DISABLED")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)