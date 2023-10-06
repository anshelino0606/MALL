//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_MALL_H
#define MALL_MALL_H

#include "../Shop/Shop.h"
#include "ENGINE/GameLevel/GameObject.h"
#include "ENGINE/GameLevel/GameLevel.h"
#include "ENGINE/Renderer/SpriteRenderer.h"
#include "ENGINE/Texture/texture.h"
#include "ENGINE/Shader/shader.h"
#include "ENGINE/ResourceManager/resourceManager.h"
#include "ENGINE/IO/keyboard.h"
#include "ENGINE/IO/mouse.h"
#include "ENGINE/IO/camera.h"

enum class GameStates {
    GAME_ACTIVE,
    GAME_IN_SHOP,
    GAME_IN_CART
};

class Mall {

public:

    /*
     * CONSTRUCTORS
     */
    Mall(unsigned int width, unsigned int height);

    /*
     * GRAPHICS
     */

    GameLevel level;
    GameStates state;

    void init();
    void processInput(float dt);
    void update(float dt);
    void render();
    void doCollisions();

    void fromShopToCart();


    /*
     * DESTRUCTOR
     */
    ~Mall();

private:
    unsigned int width;
    unsigned int height;

    bool keys[1024];

    bool isShop;

    Camera cam;
    Shop* shop;
};


#endif //MALL_MALL_H
