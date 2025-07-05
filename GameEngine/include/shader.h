#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class shader{
    public:
        GLuint ID;
        shader(const char* vertexFile, const char* fragFile);

        void Activate();
        void Delete();
};

#endif