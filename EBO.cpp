/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\EBO.cpp                                                                #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 19th 2021, 12:12:42 pm                                                     #
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

class EBO
{
public:
    GLuint ID;
    EBO(GLuint* indices, GLsizeiptr size)
    {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }

    void Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    }

    void UnBind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void Delete()
    {
        glDeleteBuffers(1, &ID);
    }
};