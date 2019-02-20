cmake_minimum_required(VERSION 3.1)
project(AnotherTry)
message("Build Project: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
option(BUILD_LIB        "Build library"        ON)
option(BUILD_SHARED_LIB "Build shared library" ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

if (${BUILD_LIB})
   add_definitions(-DBUILD_LIB)
endif()

include_directories(lib)
add_subdirectory(lib)
add_subdirectory(apps)