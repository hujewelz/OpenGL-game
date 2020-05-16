#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>

#include <GL/glew.h>

#include "shader.hpp"
#include "texture.hpp"

class ResourceManager
{
public:
    // create a shader program from file
    static Shader CreateShader(const char *vShaderPath, const char *fShaderPath, std::string name);
    // retrieves a stored shader
    static Shader GetShader(const std::string name);

    // create a texture from file
    static Texture2D CreateTexture2D(const char *file, bool alpha, std::string name);
    // retrieves a stored texture
    static Texture2D GetTexture2D(const std::string name);

    // deallocates all loaded resources
    static void clear();

private:
    ResourceManager() {}
    // resource storage
    static std::map<std::string, Shader> shaders_;
    static std::map<std::string, Texture2D> textures_;

    static Texture2D loadTextureFromFile(const char *file, bool alpha);
};

#endif