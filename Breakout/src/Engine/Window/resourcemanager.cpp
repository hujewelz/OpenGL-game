#include "resourcemanager.hpp"
#include "stb_image.h"

#include <iostream>

// Instantiate static variables
std::map<std::string, Shader> ResourceManager::shaders_;
std::map<std::string, Texture2D> ResourceManager::textures_;

Shader ResourceManager::CreateShader(const char *vShaderPath, const char *fShaderPath, std::string name)
{
    Shader s = Shader(vShaderPath, fShaderPath);
    shaders_[name] = s;
    return s;
}

Shader ResourceManager::GetShader(const std::string name)
{
    return shaders_[name];
}

Texture2D ResourceManager::CreateTexture2D(const char *file, bool alpha, std::string name)
{
    Texture2D t = loadTextureFromFile(file, alpha);
    textures_[name] = t;
    return t;
}

Texture2D ResourceManager::GetTexture2D(const std::string name)
{
    return textures_[name];
}

void ResourceManager::clear()
{
    // delete all shaders
    for (auto iter : shaders_)
        glDeleteProgram(iter.second.GetProgram());

    // delete all textures
    for (auto iter : textures_)
    {
        GLuint tex = iter.second.GetID();
        glDeleteTextures(1, &tex);
    }
}

Texture2D ResourceManager::loadTextureFromFile(const char *filename, bool alpha)
{
    Texture2D texture;
    if (alpha)
    {
        texture.SetInternalFormat(GL_RGBA);
        texture.SetImageFormat(GL_RGBA);
    }

    // load image
    int width, height, nrChanels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChanels, 0);
    // std::cout << "Load texture from file: " << texture.GetID() << std::endl;
    if (data)
    {
        std::cout << "Image width: " << width << ", height: " << height << std::endl;
        texture.Generate(width, height, data);
    }
    else
    {
        std::cout << "Load image failed" << std::endl;
    }

    stbi_image_free(data);
    return texture;
}