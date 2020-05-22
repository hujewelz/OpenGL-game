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
    static Shader CreateShader(const std::string &vShaderPath, const std::string &fShaderPath, const std::string name);
    // retrieves a stored shader
    static Shader GetShader(const std::string name);

    // create a texture from file
    static Texture2D CreateTexture2D(const std::string &file, bool alpha);
    // retrieves a stored texture
    static Texture2D GetTexture2D(const std::string &file);

    // deallocates all loaded resources
    static void Clear();

private:
    ResourceManager() {}
    // resource storage
    static std::map<std::string, Shader> shaders_;
    static std::map<std::string, Texture2D> textures_;

    static const std::string GetFileName(const std::string &file);
    static Texture2D loadTextureFromFile(const std::string &file, bool alpha);
};

#endif