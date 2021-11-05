/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\GUI\element.cpp                                                        #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI\GUI                                                                 #
# Created Date: Monday, September 20th 2021, 12:20:05 am                                                     #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
#pragma once
#include <projectX/tools/strings.cpp>
#ifndef PX_MAIN
    #include "main.cpp"
#endif
#ifndef PX_GL_IND_ARRAY_SIZE
    #define PX_GL_IND_ARRAY_SIZE 100
#endif
#ifndef PX_GL_VERT_ARRAY_SIZE
    #define PX_GL_VERT_ARRAY_SIZE 500
#endif
//? i just want to mention that because of microsofts incompetence i litterally have to waste 
//? ~2500 Bytes for alsmost every element, 
//? this is pathetic considering Clang and GCC both support VLA's and microsoft,
//? a litterall $2.24T (according to google (09/22/2021)) company apparently just can't
//? (i litterally don't understand how a company this incompetent could add $700B it's 
//? market cap in just a year ($1.5T to $2.24T))
namespace px::gui
{
    void(*alternateSysoutFunc)(std::string) = nullptr;
    class Element
    {
    private:
        std::list<Element> Elements;
        std::list<std::list<GLfloat>> list_vertices;
        std::list<GLuint> list_indices;

    public:
        Shader shader;
        int x = 0;
        int y = 0;
        int z = 0;
        Element* parent;
        unsigned long long pxID;

        Element(){}
        Element(Element* parent,unsigned long long pxID)
            : parent(parent), pxID(pxID){}
        ~Element()
            {this->Delete();}

        void loadShader(std::string vertexFile, std::string fragmentFile)
            {this->shader = Shader(vertexFile,fragmentFile);}

        void addVertice(std::list<GLfloat> glfl)
            {this->list_vertices.push_back(glfl);}

        void addIndice(GLuint i)
            {this->list_indices.push_back(i);}

        void update()
        {
            if(alternateSysoutFunc != nullptr)
                alternateSysoutFunc(px::InfoPrefix()+"updating element:0x"+px::pointerToString(this)+"\n");
            else
                std::cout << px::InfoPrefix() << "updating element:0x" << this << std::endl;
            this->shader.Activate();
            // draw
            GLfloat vertices[PX_GL_VERT_ARRAY_SIZE];
            GLuint  indices[PX_GL_IND_ARRAY_SIZE];
            int III = 0;
            for(std::list<GLfloat> I : this->list_vertices)
                for(GLfloat II : I)
                    vertices[III++] = II;
            int IV = 0;
            for(GLuint I : this->list_indices)
                indices[IV++] = I;

            VAO VAO1;
            VAO1.Bind();

            VBO VBO1(vertices, sizeof(vertices));
            EBO EBO1(indices, sizeof(indices));

            VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, (this->list_vertices.size() * III) * sizeof(float), (void*)0);
            VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, (this->list_vertices.size() * III) * sizeof(float), (void*)(3 * sizeof(float)));
            //VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glDrawElements(GL_TRIANGLES, this->list_indices.size(), GL_UNSIGNED_INT, 0);
            VAO1.UnBind();
            VBO1.UnBind();
            EBO1.UnBind();

            //clean up memory
            //delete[] vertices;
            //delete[] indices;

            //update subelements
            for(Element I : this->Elements)
                I.update();
        }

        Element* addElement(Element e)
            {this->Elements.push_back(e);return &this->Elements.back();}

        //void removeElement(unsigned long long pxID)
        //{
        //    int II = 0;
        //    Element del;
        //    for(Element I : this->Elements)
        //        if(I.pxID == pxID)
        //            del = I;
        //    this->Elements.remove(del);
        //}

        void Delete()
        {
            for(Element I : this->Elements)
                I.Delete();
        }

        unsigned long long getPxID()
            {return this->pxID;}
    };
}