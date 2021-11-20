/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\ENTRY_POINT.cpp                                                        #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Saturday, September 18th 2021, 7:34:50 pm                                                    #
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
#include <list>
#include <projectX/AUTOCONFIG.h>
#include <projectX/sysout.h>
#include "2D.cpp"
#include "RGB.cpp"
#include "shaderClass.cpp"
#include "EBO.cpp"
#include "VAO.cpp"
#include "stb.cpp"
#include "texture.cpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
px::gl::RGBA backgroundDefault(20,20,20,10);
std::string basePath = "C:\\PX_WIN_UI\\projectX_WIN_GUI\\";
std::string baseShaderPath = "C:\\PX_WIN_UI\\projectX_WIN_GUI\\shader\\";
std::string baseTexturePath = "C:\\PX_WIN_UI\\projectX_WIN_GUI\\textures\\";
#define FRAME_WIDTH 800
#define FRAME_HEIGHT 800

#include "GUI/GUI.cpp"
#include "GUI/button.cpp"
using px::gl::_2DPoint;
using px::gl::_2DPointLS;
using px::gl::RGBA;
using px::gl::toFloat;
void ENTRY_POINT(GLFWwindow* window)
{
    //gladLoadGL();
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,FRAME_WIDTH,FRAME_HEIGHT);
    px::gl::setColor(backgroundDefault);

    px::gui::GUI gui;
    px::gui::button btn(nullptr, 1);
    btn.prepare(_2DPoint(300,300),_2DPoint(400,400),RGBA(20,255,255,255),"");
    gui.addElement(btn);

    //GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    //texture
    //Texture pogCat(baseTexturePath+"pog_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    //pogCat.texUnit(shaderProgram, "tex0", 0);

    while(!glfwWindowShouldClose(window))
    {
        px::gl::setColor(backgroundDefault);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //model matrix
        //glm::mat4 model = glm::mat4(1.0f);
        //glm::mat4 view = glm::mat4(1.0f);
        //glm::mat4 proj = glm::mat4(1.0f);

        //model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f,1.0f,0.0f));

        //view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
        //proj = glm::perspective(glm::radians(45.0f), (float)(FRAME_WIDTH/FRAME_HEIGHT), 0.1f, 100.0f);

        //int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        //int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        //glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

        //glUniform1f(uniID, 0.9f);

        //update GUI
        gui.update();

        //swap buffers
        glfwSwapBuffers(window);
        // take care of events
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}