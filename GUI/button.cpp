/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\GUI\button.cpp                                                         #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI\GUI                                                                 #
# Created Date: Monday, September 20th 2021, 12:05:36 am                                                     #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
#pragma once
#ifndef PX_MAIN
    #include "main.cpp"
#endif
using px::gl::_2DPoint;
using px::gl::_2DPointLS;
using px::gl::RGBA;
using px::gl::toFloat;
namespace px::gui
{
    class button : public Element
    {
    public:
        using Element::Element;
        void prepare(_2DPoint start, _2DPoint end, RGBA rgba, std::string text = "")
        {
            _2DPointLS upperLeft (0,0);
            _2DPointLS upperRight(0,0);
            _2DPointLS lowerLeft (0,0);
            _2DPointLS lowerRight(0,0);
            if(this->parent != nullptr)
            {
                upperLeft  = _2DPointLS(_2DPoint(start.y+this->parent->x,start.x+this->parent->y));
                upperRight = _2DPointLS(_2DPoint(start.y+this->parent->x,end.x  +this->parent->y));
                lowerLeft  = _2DPointLS(_2DPoint(start.x+this->parent->x,end.y  +this->parent->y));
                lowerRight = _2DPointLS(_2DPoint(end.y  +this->parent->x,end.x  +this->parent->y));
            }
            else
            {
                upperLeft  = _2DPointLS(_2DPoint(start.y,start.x));
                upperRight = _2DPointLS(_2DPoint(start.y,end.x  ));
                lowerLeft  = _2DPointLS(_2DPoint(start.x,end.y  ));
                lowerRight = _2DPointLS(_2DPoint(end.y  ,end.x  ));
            }
            this->addVertice({upperLeft.x ,upperLeft.y , 0.0f, toFloat(rgba.r), toFloat(rgba.g), toFloat(rgba.b)});//upper left
            this->addVertice({upperRight.x,upperRight.y, 0.0f, toFloat(rgba.r), toFloat(rgba.g), toFloat(rgba.b)});//upper right
            this->addVertice({lowerLeft.x ,lowerLeft.y , 0.0f, toFloat(rgba.r), toFloat(rgba.g), toFloat(rgba.b)});//lower left
            this->addVertice({lowerRight.x,lowerRight.y, 0.0f, toFloat(rgba.r), toFloat(rgba.g), toFloat(rgba.b)});//lower right
            this->addIndice(0);
            this->addIndice(2);
            this->addIndice(1);
            this->addIndice(0);
            this->addIndice(3);
            this->addIndice(2);
        }
    };
}