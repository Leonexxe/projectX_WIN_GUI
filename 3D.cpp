/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\3D.cpp                                                                 #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 19th 2021, 8:09:14 pm                                                      #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
namespace px::gl
{
    class _3DPoint {
    public:
        int x, y, z;
        _3DPoint(int x, int y, int z)
            : x(x), y(y), z(z){}
    };
}