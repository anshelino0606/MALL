//
// Created by Anhelina Modenko on 10.08.2023.
//

#include "GameLevel.h"
#include "../ResourceManager/resourceManager.h"

#include <fstream>
#include <sstream>

enum class TileType {
    Empty = 0,
    BarrierFull = 1,
    BarrierHalf = 2,
    Shop = 3
};

void GameLevel::load(const char *file, unsigned int width, unsigned int height) {
//    this->tiles.clear();

    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;

    if (fstream) {
        while (std::getline(fstream, line)) {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode)
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->init(tileData, width, height);
    }
}

void GameLevel::draw(SpriteRenderer &renderer) {
    for (GameObject &tile : this->tiles)
        tile.Draw(renderer);
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int width, unsigned int height) {
    unsigned int heightMap = tileData.size();
    unsigned int widthMap = tileData[0].size();

    float unit_width = width / static_cast<float>(widthMap);
    float unit_height = height / static_cast<float>(heightMap);

    unsigned int tileSize = 32;

    for (unsigned int y = 0; y < height; ++y) {
        if (y>=tileData.size())
            continue;
        for (unsigned int x = 0; x < width; ++x) {
            if (x >= tileData.size())
                continue;

            unsigned int tileCode = tileData[y][x];
            glm::vec2 pos(x * tileSize, y * tileSize);
            glm::vec2 size(tileSize, tileSize);

            TileType tileType = static_cast<TileType>(tileCode);

            if (tileType == TileType::Empty)
                continue;

            Texture2D tex = ResourceManager::getTexture("board");

            glm::vec4 color = glm::vec4(1.0f);
            color.a = 0.0f;
            // handle other
            GameObject obj(pos, size, tex, color, glm::vec2(0.0f));

            this->tiles.push_back(obj);


        }
    }
}