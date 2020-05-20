#include "texture.hpp"

Texture2D::Texture2D()
    : width_(0), height_(0), internal_format_(GL_RGB), image_format_(GL_RGB),
      wrap_s_(GL_REPEAT), wrap_t_(GL_REPEAT), filter_min_(GL_LINEAR), filter_max_(GL_LINEAR)
{
    glGenTextures(1, &ID_);
}

void Texture2D::Generate(int width, int height, const unsigned char *data)
{
    width_ = width;
    height_ = height;

    glBindTexture(GL_TEXTURE_2D, ID_);
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format_, width_, height_, 0, image_format_, GL_UNSIGNED_BYTE, data);
    //set texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_min_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_max_);
    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, ID_);
}

// set the format of texture object
void Texture2D::SetInternalFormat(unsigned int tex_format)
{
    internal_format_ = tex_format;
}
// set the format of loaded image
void Texture2D::SetImageFormat(unsigned int image_format)
{
    image_format_ = image_format;
}

// set wrapping mode on S axis
void Texture2D::SetWrapS(unsigned int wrap_s)
{
    wrap_s_ = wrap_s;
}
// set wrapping mode on T axis
void Texture2D::SetWrapT(unsigned int wrap_t)
{
    wrap_t_ = wrap_t;
}
// set filtering mode when texture pixels < screen pixels
void Texture2D::SetFilterMin(unsigned int filter_min)
{
    filter_min_ = filter_min;
}
// set filering mode when texture pixels > screen pixels
void Texture2D::SetFilterMax(unsigned int filter_max)
{
    filter_max_ = filter_max;
}