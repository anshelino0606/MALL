//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_SHOPPINGCART_H
#define MALL_SHOPPINGCART_H

#include "../Item/Item.h"
#include "ENGINE/Texture/texture.h"
#include <iostream>

class ShoppingCart {
public:
    
    /*
     * CONSTRUCTORS
     */
    
    // Without parameters
    ShoppingCart();
    
    // Init constructor
    ShoppingCart(unsigned int width, unsigned int height, Texture2D tex, std::vector<Item> items);
    
    // Copy constructor
    ShoppingCart(const ShoppingCart& other);
    
    // Move constructor
    ShoppingCart(ShoppingCart&& shoppingCart);
    
    /*
     * FUNCTIONALITY
     */

    void addToCart(const Item& item);
    void removeFromCart(const Item& item);
    void printAllItems();
    
    /*
     * GETTERS AND SETTERS
     */
    
    float getHeightOfCart();
    float getWidthOfCart();
    std::vector<Item> getItems();
    std::vector<Item> getItemsVec();
    
    void setHeightOfCart(float height);
    void setWidthOfCart(float width);

    /*
     * Calculates optimal space for items in cart
     */
    float calculateOptimalSpace(float totalRowWidth, float totalRowHeight);
    std::vector<std::vector<Item>> calculateOptimalPlacement(const std::vector<Item>& items, float rowLimit);
    
    /*
     * GRAPHICS PART
     */

    void processInput(float dt);
    void render();
    void init();
    void update(float dt);
    void doCollisions();
    void doOptimalPlacement();
    
private:

    Texture2D tex;

    unsigned int currentCapacity;
    unsigned int maxCapacity;
    
    float width;
    float height;
    
    std::vector<Item> items;
    
    bool isOpen;
};


#endif //MALL_SHOPPINGCART_H
