#include "../include/shader.h"

std::string get_file_contents(const char* filename){
    std::ifstream in(filename, std::ios::binary);
    if (in){
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    std::cerr << "ERROR: Could not open file: " << filename << std::endl;
    throw std::runtime_error("File not found: " + std::string(filename));
}

shader::shader(const char* vertexFile, const char* fragFile){
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragCode = get_file_contents(fragFile);

    const char* vertSrc = vertexCode.c_str();
    const char* fragSrc = fragCode.c_str();

    //creating the vertex shader via gl
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertSrc, NULL);
    //must complie source code on the spot
    glCompileShader(vertexShader);

    //same thing with fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragSrc, NULL);
    glCompileShader(fragmentShader);

    //creating shader program to load the shaders
    ID = glCreateProgram();
    //attaching shaders to the program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    //connecting the program to gl
    glLinkProgram(ID);

    //delete shaders as they are in the program now
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void shader::Activate(){
    glUseProgram(ID);
}
void shader::Delete(){
    glDeleteProgram(ID);
}