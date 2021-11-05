/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\GUI\GUI.cpp                                                            #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI\GUI                                                                 #
# Created Date: Monday, September 20th 2021, 12:05:30 am                                                     #
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
#include "element.cpp"
namespace px::gui
{
    class GUI
    {
    private:
        std::list<Element> Elements;
    public:
        GUI(){}
        ~GUI(){this->Delete();}

        void update()
        {
            if(alternateSysoutFunc != nullptr)
                alternateSysoutFunc(px::InfoPrefix()+"updating gui:0x"+px::pointerToString(this)+"\n");
            else
                std::cout << px::InfoPrefix() << "updating gui:0x" << this << std::endl;
            for(Element I : this->Elements)
                I.update();
        }

        Element* addElement(Element e)
            {this->Elements.push_back(e);return &this->Elements.back();}

        void Delete()
        {
            for(Element I : this->Elements)
                I.Delete();
        }
    };
}