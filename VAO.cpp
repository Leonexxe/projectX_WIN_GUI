/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\VAO.cpp                                                                #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 19th 2021, 12:17:31 pm                                                     #
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
#include "VBO.cpp"
class VAO
{
public:
    GLuint ID;
    VAO()
    {
        glGenVertexArrays(1, &ID);
    }

    void LinkAttrib(VBO& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
    {
        vbo.Bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        //Enable the vertex attribute so that OpenGL know to use it
        glEnableVertexAttribArray(layout);
        vbo.UnBind();
    }

    void Bind()
    {
        glBindVertexArray(ID);
    }

    void UnBind()
    {
        glBindVertexArray(0);
    }

    void Delete()
    {
        glDeleteVertexArrays(1, &ID);
    }
};