##############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\CMakeLists.txt                                                         #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 12th 2021, 3:15:02 pm                                                      #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
##############################################################################################################
cmake_minimum_required(VERSION 3.20.0)
project(projectX VERSION 0.1.0)
include(CTest)
enable_testing()

add_executable(projectX main.cpp)

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
target_include_directories(projectX PUBLIC C:/cppLIB/include C:/cppLIB/GLFW/include C:/cppLIB/include/glad C:/cppLIB C:/cppLIB/lib)
#target_link_libraries(projectX C:/cppLIB/glfw3.lib)
add_subdirectory(C:/cppLIB/GLFW [binary_dir][EXCLUDE_FROM_ALL])
target_link_libraries(projectX glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(projectX OpenGL::GL)

#
#flags
#
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lGL -lglfw3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()

#copy files
add_dependencies(projectX LCC)
add_custom_target(LCC libcopy)

#end
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
