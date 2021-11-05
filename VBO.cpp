/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\VBO.cpp                                                                #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 19th 2021, 12:07:23 pm                                                     #
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

class VBO
{
public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size)
    {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    void Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void UnBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Delete()
    {
        glDeleteBuffers(1, &ID);
    }
};