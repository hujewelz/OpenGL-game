#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture2D
{
public:
    Texture2D();
    // generate image with data
    void Generate(int width, int height, const unsigned char *data);
    // binds the texture as the current active GL_TEXTURE_2D texture object
    void Bind() const;

    GLuint GetID() const { return ID_; }

    // return the format of texture object
    unsigned int GetInternalFormat() const { return internal_format_; }
    // return the format of loaded image
    unsigned int GetImageFormat() const { return image_format_; }
    // return wrapping mode on S axis
    unsigned int GetWrapS() const { return wrap_s_; }
    // return wrapping mode on T axis
    unsigned int GetWrapT() const { return wrap_t_; }
    // return filtering mode when texture pixels < screen pixels
    unsigned int GetFilterMin() const { return filter_min_; }
    // return filering mode when texture pixels > screen pixels
    unsigned int GetFilterMax() const { return filter_max_; }

    // set the format of texture object
    void SetInternalFormat(unsigned int tex_format);
    // set the format of loaded image
    void SetImageFormat(unsigned int image_format);
    // set wrapping mode on S axis
    void SetWrapS(unsigned int wrap_s);
    // set wrapping mode on T axis
    void SetWrapT(unsigned int wrap_t);
    // set filtering mode when texture pixels < screen pixels
    void SetFilterMin(unsigned int filter_min);
    // set filering mode when texture pixels > screen pixels
    void SetFilterMax(unsigned int filter_max);

private:
    GLuint ID_;
    int width_;
    int height_;
    // format of texture object
    unsigned int internal_format_;
    // format of loaded image
    unsigned int image_format_;
    // wrapping mode on S axis
    unsigned int wrap_s_;
    // wraping mode on T axis
    unsigned int wrap_t_;
    // filtering mode if texture pixels < screen pixels
    unsigned int filter_min_;
    // filtering mode if texture pixels > screen pixels
    unsigned int filter_max_;
};

#endif