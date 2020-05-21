#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader();
    Shader(const char *vShaderPath, const char *fShaderPath);
    ~Shader();
    void Use();

    GLuint GetProgram() const { return program_; }

    // utility functions
    void SetInt(const char *name, int value, bool useShader = false);
    void SetFloat(const char *name, float value, bool useShader = false);
    void SetVector2f(const char *name, float x, float y, bool useShader = false);
    void SetVector3f(const char *name, float x, float y, float z, bool useShader = false);
    void SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false);

    void SetMatrix4(const char *name, const glm::mat4 &mat, bool userShader = false);

private:
    GLuint program_;
    void LinkShader(const char *vShaderPath, const char *fShaderPath);
    GLuint CompileSharder(const char *shaderpath, GLenum type);
};

#endif