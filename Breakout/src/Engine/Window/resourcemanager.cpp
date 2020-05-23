#include "resourcemanager.hpp"
#include "stb_image.h"

#include <iostream>
#include <functional>

// Instantiate static variables
std::map<std::string, Shader> ResourceManager::shaders_;
std::map<std::string, Texture2D> ResourceManager::textures_;

Shader ResourceManager::CreateShader(const std::string &vShaderPath, const std::string &fShaderPath, std::string name)
{
    std::cout << "CreateShader" << std::endl;
    // std::map<std::string, Shader>::iterator iter = shaders_.find(name);
    // if (iter != shaders_.end())
    // {
    //     std::cout << "Shader: " << shaders_[name].GetProgram() << std::endl;
    //     return shaders_[name];
    // }

    Shader s(vShaderPath, fShaderPath);
    s.LinkShader();
    shaders_[name] = s;
    return s;
}

Shader ResourceManager::GetShader(const std::string name)
{
    return shaders_[name];
}

Texture2D ResourceManager::CreateTexture2D(const std::string &file, bool alpha)
{
    const std::string name = GetFileName(file);
    // load texture from cache first.
    if (textures_.count(name))
    {
        // std::cout << "Create texture: " << textures_[name].GetID() << std::endl;
        return textures_[name];
    }
    textures_[name] = loadTextureFromFile(file, alpha);
    return textures_[name];
}

Texture2D ResourceManager::GetTexture2D(const std::string &file)
{
    const std::string name = GetFileName(file);
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

Texture2D ResourceManager::loadTextureFromFile(const std::string &filename, bool alpha)
{
    Texture2D texture;
    if (alpha)
    {
        texture.SetInternalFormat(GL_RGBA);
        texture.SetImageFormat(GL_RGBA);
    }

    // load image
    int width, height, nrChanels;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrChanels, 0);
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