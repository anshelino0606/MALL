//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_SHOPPINGCART_H
#define MALL_SHOPPINGCART_H

#include "../Item/Item.h"

class ShoppingCart {
public:
    
    /*
     * CONSTRUCTORS
     */
    
    // Without parameters
    ShoppingCart();
    
    // Init constructor
    ShoppingCart(unsigned int width, unsigned int height, Item* items);
    
    // Copy constructor
    ShoppingCart(const ShoppingCart& shoppingCart);
    
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
    Item* getItems();
    
    void setHeightOfCart(float height);
    void setWidthOfCart(float width);

    /*
     * Calculates optimal space for items in cart
     */
    float calculateOptimalPlacement();
    
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
    
    float width;
    float height;
    
    Item* items;
    
    bool isOpen;
};


#endif //MALL_SHOPPINGCART_H