//
// Created by Anhelina Modenko on 10.08.2023.
//

#ifndef MALL_1_GAMELEVEL_H
#define MALL_1_GAMELEVEL_H

#include "GameObject.h"
#include <vector>
#include "../Renderer/SpriteRenderer.h"

class GameLevel {
public:
    std::vector<GameObject> tiles;

    GameLevel() {}

    void load(const char *file, unsigned int width, unsigned height);
    void draw(SpriteRenderer &renderer);

private:
    void init(std::vector<std::vector<unsigned int>> tileData,
              unsigned int width,
              unsigned int height);

};


#endif //MALL_1_GAMELEVEL_H
