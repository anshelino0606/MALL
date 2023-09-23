//
// Created by Anhelina Modenko on 10.08.2023.
//

#ifndef MALL_1_GAMEOBJECT_H
#define MALL_1_GAMEOBJECT_H

#include "Addons/glad/glad.h"
#include <glm/glm.hpp>

#include "./Graphics//texture.h"
#include "Game/Renderer/SpriteRenderer.h"
//#include "./Algorithms/Collisions/bounds.h"


class GameObject {
public:
    glm::vec2 pos;
    glm::vec2 size;
    glm::vec2 velocity;

    glm::vec3 color;

    float rotation;
    bool isBarrier;
    bool isHalfBarrier;
    bool isShop;
    bool stuck;

//    BoundingRegion boundingRegion;

    Texture2D Sprite;
    GameObject();
    GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f), bool isBarrier = false, bool isShop = false, bool isHalfBarrier = false);

    virtual void Draw(SpriteRenderer &renderer);
};


#endif //MALL_1_GAMEOBJECT_H
