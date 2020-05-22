#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader();
    Shader(const std::string &vShaderPath, const std::string &fShaderPath);
    ~Shader();
    void Use();

    GLuint GetProgram() const { return program_; }
    void LinkShader();

    // utility functions
    void SetInt(const char *name, int value, bool useShader = false);
    void SetFloat(const char *name, float value, bool useShader = false);
    void SetVector2f(const char *name, float x, float y, bool useShader = false);
    void SetVector3f(const char *name, float x, float y, float z, bool useShader = false);
    void SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false);

    void SetMatrix4(const char *name, const glm::mat4 &mat, bool userShader = false);

private:
    GLuint program_;
    std::string v_shader_path_;
    std::string f_shader_path_;
    GLuint CompileSharder(const std::string &shaderpath, GLenum type);
};

#endif