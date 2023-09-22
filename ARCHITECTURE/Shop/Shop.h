//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef ENGINE_MALL_SHOP_H
#define ENGINE_MALL_SHOP_H

#include "../Item/Item.h"

class Shop {

public:

    /*
     * CONSTRUCTORS
     */

    // Without parameters
    Shop();

    // Init constructor
    Shop(const std::string& name, unsigned int maxCapacity);

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
