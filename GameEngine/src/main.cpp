#include <iostream>
#include <math.h>

#include "../include/glad/glad.h"
#include "../external/GLFW/include/glfw3.h"

#include "../include/shader.h"
#include "../include/VAO.h"
#include "../include/VBO.h"
#include "../include/EBO.h"

int main(){
    glfwInit(); //initializing

    //setting opengl version to use
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat verticies[] = {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,

        -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
        0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
        0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
    };
    GLuint indicies[] = {
        0, 3, 5,
        3, 2, 4,
        5, 4, 1
    };

    //creating window
    GLFWwindow* window = glfwCreateWindow(800, 800, "sushi maker", nullptr, nullptr);
    if (window == NULL){
        std::cout << "WINDOW NOT CREATED" << std::endl;
        glfwTerminate();
        return -1;
    }
    //making the window appear
    glfwMakeContextCurrent(window);

    //load glad so it configs ogl
    gladLoadGL();
    
    //specify viewport of ogl in the window
    glViewport(0, 0, 800, 800);

    shader shaderProgram("../shaders/default.vert", "../shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(verticies, sizeof(verticies));
    EBO EBO1(indicies, sizeof(indicies));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();
    
    //main while loop
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        
        //take care of events like resize and moving
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    //delete window
    glfwDestroyWindow(window);
    glfwTerminate(); //terminating
    
    return 0;
}