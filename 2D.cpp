/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\2d.cpp                                                                 #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Saturday, September 18th 2021, 9:09:00 pm                                                    #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
namespace px::gl
{
    unsigned long long GLOBAL_MONITOR_WIDTH  = 1920;
    unsigned long long GLOBAL_MONITOR_HEIGHT = 1080;
    class _2DPoint {
    public:
        int x, y;
        _2DPoint(int x, int y)
            : x(x), y(y){}
    };

    class _2DPointLS
    {
    public:
        float x, y;
        _2DPointLS(float x, float y)
            : x(x), y(y){}

        _2DPointLS(_2DPoint screenSpace)
            : x(2.0*screenSpace.x/GLOBAL_MONITOR_WIDTH - 1.0),
              y(1.0 - 2.0*screenSpace.y/GLOBAL_MONITOR_HEIGHT){}
    };
}