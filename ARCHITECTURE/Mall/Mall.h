//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_MALL_H
#define MALL_MALL_H

#include "../Shop/Shop.h"
#include "../../ENGINE/GameLevel/GameObject.h"
#include "../../ENGINE/GameLevel/GameLevel.h"

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

    void init();
    void processInput(float dt);
    void update(float dt);
    void render();
    void doCollisions();


    /*
     * DESTRUCTOR
     */
    ~Mall();



private:
    unsigned int width;
    unsigned int height;

    Shop* shops;
};


#endif //MALL_MALL_H
