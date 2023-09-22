//
// Created by Anhelina Modenko on 09.08.2023.
//

#ifndef MALL_1_RESOURCEMANAGER_H
#define MALL_1_RESOURCEMANAGER_H

#include <map>
#include <string>

#include "Addons/glad/glad.h"

#include "ENGINE/GRAPHICS/Texture/texture.h"
#include "ENGINE/GRAPHICS/Shader/shader.h"

// static singleton class

class Shader;
class Texture2D;

class ResourceManager {
public:
    static std::map<std::string, Shader> shaders;
    static std::map<std::string, Texture2D> textures;

    static Shader loadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
    static Shader getShader(std::string name);

    static Texture2D loadTexture(const char *file, bool alpha, std::string name);
    static Texture2D getTexture(std::string name);

    static void clear();
private:
    ResourceManager() { }

    static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    static Texture2D loadTextureFromFile(const char *file, bool alpha);
};


#endif //MALL_1_RESOURCEMANAGER_H
