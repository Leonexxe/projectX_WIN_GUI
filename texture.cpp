/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\texture.cpp                                                            #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Sunday, September 19th 2021, 7:03:23 pm                                                      #
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
class Texture
{
public:
    GLuint ID;
    GLenum type;
    Texture(std::string image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
        :type(texType)
    {
        stbi_set_flip_vertically_on_load(true);
        int widthImg, heightImg, numColCh;
        std::cout << "loading image: " << image.c_str() << "..." << std::endl;
        unsigned char* bytes = stbi_load(image.c_str(),&widthImg, &heightImg, &numColCh, 0);

        glGenTextures(1, &ID);
        glActiveTexture(slot);
        glBindTexture(texType, ID);

        glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
        glGenerateMipmap(texType);

        stbi_image_free(bytes);
        glBindTexture(texType, 0);
    }

    void texUnit(Shader& shader, const char* uniform, GLuint unit)
    {
        GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
        shader.Activate();
        glUniform1i(tex0Uni, 0);
    }

    void Bind()
    {
        glBindTexture(type, ID);
    }

    void Unbind()
    {
        glBindTexture(type, 0);
    }

    void Delete()
    {
        glDeleteTextures(1, &ID);
    }
};