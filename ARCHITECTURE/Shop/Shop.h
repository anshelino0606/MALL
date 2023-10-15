//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_SHOP_H
#define MALL_SHOP_H

#include "../Item/Item.h"
#include "../ShoppingCart/ShoppingCart.h"
#include "ENGINE/Texture/texture.h"
#include <fstream>
#include <iostream>

class Shop {

public:

    /*
     * CONSTRUCTORS
     */

    // Without parameters
    Shop();

    // Init constructor
    Shop(unsigned int height, unsigned int width, Texture2D tex, const std::string& name, unsigned int maxCapacity, Item* items = nullptr);

    // Copy constructor
    Shop(const Shop& other);

    // Move constructor
    Shop(Shop&& other) noexcept;

    /*
     * Merging two shops, so that they are combined into 3rd
     */
    Shop(const Shop& first, const Shop& second);

    /*
     * METHODS
     */

    /*
     * Reads shop from the stream
     * File is in the format of path to directory
     */

    void readFromFile(const std::string& fileName);

    /*
     * 1. Prints the shop to the console
     * 2. Prints the shop to the stream
     */
    void print() const;
    void print(std::ostream& os) const;

    /*
     * Merges two shops, so that the second one overwrites the first one
     */
    void merge(const Shop& other);

    Shop* mergeIntoAnotherShop(const Shop& other);

    /*
     * GETTERS AND SETTERS
     */

    unsigned int getMaxCapacity() const;
    unsigned int getCurrentCapacity() const;
    Item* getItems() const;
    std::string getName() const;
    void printAllItems() const;

    void setMaxCapacity(unsigned int maxCapacity);
    void setCurrentCapacity(unsigned int currentCapacity);
    void setItems(Item* items);
    void setName(const std::string& name);

    /*
     * GRAPHICS PART
     */

    void processInput(float dt);
    void render();
    void init();
    void update(float dt);
    void doCollisions();

    /*
     * OPERATORS
     */
    Shop& operator=(const Shop& other);
    Shop& operator+(const Shop& other);
    Shop& operator-(const Shop& other);
    Shop& operator+=(const Shop& other);
    Shop& operator-=(const Shop& other);

    friend std::ostream& operator<<(std::ostream& os, const Shop& shop);
    friend std::istream& operator>>(std::istream& is, Shop& shop);

    bool operator==(const Shop& other) const;
    bool operator!=(const Shop& other) const;
    bool operator<(const Shop& other) const;
    bool operator>(const Shop& other) const;
    bool operator<=(const Shop& other) const;
    bool operator>=(const Shop& other) const;


    /*
     * DESCTRUCTOR
     */

    ~Shop();

private:

    // Capacity of the shop
    unsigned int maxCapacity;
    unsigned int currentCapacity;

    // Graphics part
    Texture2D tex;
    unsigned int height;
    unsigned int width;

    // Items array
    Item* items;

    // Shop name
    std::string name;

};


#endif //ENGINE_MALL_SHOP_H
