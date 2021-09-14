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

add_executable(projectX WIN32 main.cpp)

#msvc
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

#wxWidgets
target_include_directories(projectX PUBLIC C:/wxWidgets-3.1.5/include C:/wxWidgets-3.1.5/include/msvc)
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxbase31ud.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxbase31ud_net.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxbase31ud_xml.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxexpatd.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxregexud.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxzlibd.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxjpegd.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxpngd.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxtiffd.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxscintillad.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_core.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_html.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_qa.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_xrc.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_aui.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_propgrid.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_ribbon.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_richtext.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_media.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_stc.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_webview.lib")
target_link_libraries(projectX "C:/wxWidgets-3.1.5/lib/vc_lib/wxmsw31ud_gl.lib")

#copy files
add_dependencies(projectX LCC)
add_custom_target(LCC libcopy)

#end
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
