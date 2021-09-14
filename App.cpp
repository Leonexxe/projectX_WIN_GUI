/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\App.cpp                                                                #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Tuesday, September 14th 2021, 6:12:11 pm                                                     #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
#include "include.h"
void log(std::string s)
{
    UI_FRAME->m_txt->AppendText(s);
}

void _app()
{
    log("starting client...");
}