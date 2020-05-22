#include "resourcemanager.hpp"
#include "stb_image.h"

#include <iostream>
#include <functional>

// Instantiate static variables
std::map<std::string, Shader> ResourceManager::shaders_;
std::map<std::string, Texture2D> ResourceManager::textures_;

Shader ResourceManager::CreateShader(const char *vShaderPath, const char *fShaderPath, std::string name)
{
    shaders_[name] = Shader(vShaderPath, fShaderPath);
    return shaders_[name];
}

Shader ResourceManager::GetShader(const std::string name)
{
    return shaders_[name];
}

Texture2D ResourceManager::CreateTexture2D(const char *file, bool alpha, const std::string name)
{
    textures_[name] = loadTextureFromFile(file, alpha);
    ;
    return textures_[name];
}

Texture2D ResourceManager::GetTexture2D(const std::string name)
{
    return textures_[name];
}

void ResourceManager::Clear()
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

const std::string ResourceManager::GetFileName(const std::string &file)
{
    std::hash<std::string> hash_str;
    return std::to_string(hash_str(file));
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