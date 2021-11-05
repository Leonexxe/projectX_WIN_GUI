/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\RGB.cpp                                                                #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Saturday, September 18th 2021, 7:28:21 pm                                                    #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
#pragma once
#define PX_GL_MAX_BRIGHTNESS 255.0F
namespace px::gl
{
    float toFloat(int c)
        {return float(c/PX_GL_MAX_BRIGHTNESS);}
    struct RGBA
    {
        int r,g,b,a;
        RGBA(int r, int g, int b, int a)
            :r(r),g(g),b(b),a(a){}
    };
    void setColor(int r, int g, int b, int a)
    {
        glClearColor(float(r/PX_GL_MAX_BRIGHTNESS),float(g/PX_GL_MAX_BRIGHTNESS),
                    float(b/PX_GL_MAX_BRIGHTNESS),float(a/PX_GL_MAX_BRIGHTNESS));
    }
    void setColor(RGBA rgba)
    {
        setColor(rgba.r,rgba.g,rgba.b,rgba.a);
    }
}