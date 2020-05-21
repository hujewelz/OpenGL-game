#include "shader.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char *vShaderPath, const char *fShaderPath)
{
    LinkShader(vShaderPath, fShaderPath);
}

Shader::Shader() {}

Shader::~Shader()
{
    glDeleteProgram(program_);
}

void Shader::Use()
{
    glUseProgram(program_);
}

void Shader::SetInt(const char *name, int value, bool useShader)
{
    if (useShader)
        Use();
    glUniform1i(glGetUniformLocation(program_, name), value);
}

void Shader::SetFloat(const char *name, float value, bool useShader)
{
    if (useShader)
        Use();
    glUniform1f(glGetUniformLocation(program_, name), value);
}

void Shader::SetVector2f(const char *name, float x, float y, bool useShader)
{
    if (useShader)
        Use();
    glUniform2f(glGetUniformLocation(program_, name), x, y);
}

void Shader::SetVector3f(const char *name, float x, float y, float z, bool useShader)
{
    if (useShader)
        Use();
    glUniform3f(glGetUniformLocation(program_, name), x, y, z);
}

void Shader::SetVector4f(const char *name, float x, float y, float z, float w, bool useShader)
{
    if (useShader)
        Use();
    glUniform4f(glGetUniformLocation(program_, name), x, y, z, w);
}

void Shader::SetMatrix4(const char *name, const glm::mat4 &mat, bool userShader)
{
    if (userShader)
        Use();
    glUniformMatrix4fv(glGetUniformLocation(program_, name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::LinkShader(const char *vShaderPath, const char *fShaderPath)
{
    program_ = glCreateProgram();
    GLuint vertexShader = CompileSharder(vShaderPath, GL_VERTEX_SHADER);
    GLuint fragmentShader = CompileSharder(fShaderPath, GL_FRAGMENT_SHADER);
    glAttachShader(program_, vertexShader);
    glAttachShader(program_, fragmentShader);

    glLinkProgram(program_);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLuint Shader::CompileSharder(const char *shaderpath, GLenum type)
{
    std::string sCode;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    std::cout << "SHAPER PATH:" << shaderpath << std::endl;
    try
    {
        // open the file
        shaderFile.open(shaderpath);
        std::stringstream shaderStream;
        // read file buffer to stream
        shaderStream << shaderFile.rdbuf();
        // close file
        shaderFile.close();
        sCode = shaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    const char *shaderSource = sCode.c_str();
    GLuint shader;
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar info[255];
        glGetShaderInfoLog(shader, 255, NULL, &info[0]);

        std::cout << (type == GL_VERTEX_SHADER ? "Vertex Shader" : "Fragment Shader") << "compile with error: " << info << std::endl;
    }
    return shader;
}