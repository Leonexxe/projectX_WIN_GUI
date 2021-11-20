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

set(projectXOS "OSX")

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#add_subdirectory(C:/cppLIB/GLFW [binary_dir][EXCLUDE_FROM_ALL])
include_directories([AFTER|BEFORE] [SYSTEM] /usr/local/include)
include_directories([AFTER|BEFORE] [SYSTEM] /Users/leonexxe/code/LIB)
include_directories([AFTER|BEFORE] [SYSTEM] /Users/leonexxe/code/LIB/lib)
include_directories([AFTER|BEFORE] [SYSTEM] /opt/homebrew/include)
target_link_libraries(projectX glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(projectX OpenGL::GL)

#// 
#// c++17
#// 
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang") 
  # using Clang
  message("using ${CMAKE_CXX_COMPILER_ID} configuration")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++ -Wno-c++98-compat -Wno-comment -Wno-#pragma-messages -Wno-return-type -Wno-macro-redefined -Wno-implicitly-unsigned-literal -Wno-string-compare")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  message("using ${CMAKE_CXX_COMPILER_ID} configuration")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
  message("using ${CMAKE_CXX_COMPILER_ID} configuration")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  message("using ${CMAKE_CXX_COMPILER_ID} configuration")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
  message("could not identify C++ compiler (${CMAKE_CXX_COMPILER_ID})")
endif()

#// 
#// openGL
#//  
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgl -lglfw")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL -framework GLUT -lglew -L\"/opt/homebrew/lib\"")

message("CXX flags: \"${CMAKE_CXX_FLAGS}\"") 

#end
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
