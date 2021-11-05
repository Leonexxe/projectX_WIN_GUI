#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#pragma warning(disable:4146)

//! new approach with openGL
#include <iostream>
#include "glad.c"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define PX_MAIN
#include "ENTRY_POINT.cpp"

//? https://www.youtube.com/watch?v=45MIykWJ-C4 (really good glfw course)
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 800, "projectX", NULL, NULL);
    /* error checking */if(window == NULL){std::cout << "Failed to create GLFW window" << std::endl;glfwTerminate();return -1;}
    glfwMakeContextCurrent(window);
    //- code goes here
    ENTRY_POINT(window);
    //- code ends here
//    while(!glfwWindowShouldClose(window))
//        update(window);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
