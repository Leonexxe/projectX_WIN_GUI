/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\shaderClass.cpp                                                        #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 19th 2021, 11:55:56 am                                                     #
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
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if(in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    throw(errno);
}

class Shader
{
public:
    GLuint ID;
    Shader(){}
    Shader(std::string vertexFile, std::string fragmentFile)
    {
        // get shaders
        std::string vertexCode = get_file_contents(vertexFile.c_str());
        std::string fragmentCode = get_file_contents(fragmentFile.c_str());
        const char* vertexSource = vertexCode.c_str();
        const char* fragmentSource = fragmentCode.c_str();

        //load shaders
        //vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);
        compileErrors(vertexShader, "VERTEX");

        //fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);
        compileErrors(fragmentShader, "FRAGMENT");

        //shader program
        this->ID = glCreateProgram();
        glAttachShader(this->ID, vertexShader);
        glAttachShader(this->ID, fragmentShader);
        glLinkProgram(this->ID);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Activate()
    {
        glUseProgram(ID);
    }

    void Delete()
    {
        glDeleteProgram(ID);
    }

    //- code: https://github.com/VictorGordan/opengl-tutorials/blob/main/YoutubeOpenGL%205%20-%20Shaders/shaderClass.cpp
    void compileErrors(unsigned int shader, const char* type)
    {
    	// Stores status of compilation
    	GLint hasCompiled;
    	// Character array to store error message in
    	char infoLog[1024];
    	if (type != "PROGRAM")
    	{
    		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
    		if (hasCompiled == GL_FALSE)
    		{
    			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
    			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
    		}
    	}
    	else
    	{
    		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
    		if (hasCompiled == GL_FALSE)
    		{
    			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
    			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
    		}
    	}
    }
};