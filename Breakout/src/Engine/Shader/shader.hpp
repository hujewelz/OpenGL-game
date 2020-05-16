#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

class Shader
{
public:
    Shader();
    Shader(const char *vShaderPath, const char *fShaderPath);
    ~Shader();
    void Use();

    GLuint GetProgram() { return program_; }

    // utility functions
    void SetInt(const char *name, int value, bool useShader = false);
    void SetFloat(const char *name, float value, bool useShader = false);
    void SetVector2f(const char *name, float x, float y, bool useShader = false);
    void SetVector3f(const char *name, float x, float y, float z, bool useShader = false);
    void SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false);

private:
    GLuint program_;
    void LinkShader(const char *vShaderPath, const char *fShaderPath);
    GLuint CompileSharder(const char *shaderpath, GLenum type);
};

#endif