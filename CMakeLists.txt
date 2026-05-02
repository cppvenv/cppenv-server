cmake_minimum_required(VERSION 3.20)
project(cppenv-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
#    "${CMAKE_CURRENT_SOURCE_DIR}/cppenv-core/cmake"
)

find_package(PkgConfig REQUIRED)

include(Dependencies)
include(DoxygenTarget)
#include(GNUInstallDirs)