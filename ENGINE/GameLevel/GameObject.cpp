//
// Created by Anhelina Modenko on 10.08.2023.
//

#include "GameObject.h"

GameObject::GameObject()
    : pos(0.0f, 0.0f), size(1.0f, 1.0f), velocity(0.0f), color(0.0f), rotation(0.0f), Sprite(), isBarrier(false), isShop(false)
    {}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity, bool isBarrier, bool isShop, bool isHalfBarrier)
    : pos(pos), size(size), velocity(velocity), color(color), rotation(0.0f), Sprite(sprite), isBarrier(isBarrier), isShop(isShop), isHalfBarrier(isHalfBarrier)
    {}


void GameObject::Draw(SpriteRenderer &renderer) {
    renderer.DrawSprite(this->Sprite, this->pos, this->size, this->rotation, this->color);
}