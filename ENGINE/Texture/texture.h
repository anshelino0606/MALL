#ifndef TEXTURE_H
#define TEXTURE_H

#include "Addons/glad/glad.h"
#include <GLFW/glfw3.h>

#include <assimp/scene.h>

#include "Addons/stb/stb_image.h"

/*
    class to represent texture
*/

class Shader;

class Texture2D {
public:
    /*
        constructor
    */
    Texture2D();

    // initialize with name
//    Texture2D(std::string name);

    // initialize with image path and type
//    Texture2D(std::string dir, std::string path, aiTextureType type);

    // generate texture id
//    void generate();

    // load texture from path
//    void load(bool flip = true);

    void generate(unsigned int width, unsigned int height, unsigned char* data);

//    static void setParams(GLenum texMinFilter = GL_NEAREST,
//        GLenum texMagFilter = GL_NEAREST,
//        GLenum wrapS = GL_REPEAT,
//        GLenum wrapT = GL_REPEAT);

    // bind texture id
    void bind() const;

//    GLenum getFormat();

    void cleanup();


    /*
        texture object values
    */
    
    // texture id
    unsigned int id;
    // texture type
    aiTextureType type;
    //
    unsigned int width;
    unsigned int height;
    //
    unsigned int Internal_Format; // format of texture object
    unsigned int Image_Format; // format of loaded image
    unsigned int Wrap_S; // wrapping mode on S axis
    unsigned int Wrap_T; // wrapping mode on T axis
    unsigned int Filter_Min; // filtering mode if texture pixels < screen pixels
    unsigned int Filter_Max; // filtering mode if texture pixels > screen pixels
    // name
    std::string name;
    // directory of image
    std::string dir;
    // name of image
    std::string path;
};

#endif