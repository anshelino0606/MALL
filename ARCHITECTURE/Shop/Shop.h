//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef ENGINE_MALL_SHOP_H
#define ENGINE_MALL_SHOP_H

#include "../Item/Item.h"
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
    Shop(const std::string& name, unsigned int maxCapacity, Item* items);

    // Copy constructor
    Shop(const Shop& other);

    // Move constructor
    Shop(Shop&& other) noexcept;

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
     * GETTERS AND SETTERS
     */

    unsigned int getMaxCapacity() const;
    unsigned int getCurrentCapacity() const;
    Item* getItems() const;
    std::string getName() const;

    void setMaxCapacity(unsigned int maxCapacity);
    void setCurrentCapacity(unsigned int currentCapacity);
    void setItems(Item* items);
    void setName(const std::string& name);

    /*
     * DESCTRUCTOR
     */

    ~Shop();

private:

    // Capacity of the shop
    unsigned int maxCapacity;
    unsigned int currentCapacity;

    // Items array
    Item* items;

    // Shop name
    std::string name;

};


#endif //ENGINE_MALL_SHOP_H
