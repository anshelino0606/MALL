//
// Created by Anhelina Modenko on 09.08.2023.
//

#ifndef MALL_1_SPRITERENDERER_H
#define MALL_1_SPRITERENDERER_H
#pragma once

#include "Addons/glad/glad.h"
#include <GLFW/glfw3.h>
#include "ENGINE/GRAPHICS/Texture/texture.h"
#include "ENGINE/GRAPHICS/Shader/shader.h"

class Game;
class Shop;


class SpriteRenderer {
public:
    SpriteRenderer(const Shader &shader);
    ~SpriteRenderer();

    void DrawSprite(const Texture2D texture, glm::vec2 position,
                           glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
                           glm::vec3 color = glm::vec3(1.0f));
private:
    Shader       shader;
    unsigned int quadVAO;

    void initRenderData();
};



#endif //MALL_1_SPRITERENDERER_H
