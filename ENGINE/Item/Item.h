//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_ITEM_H
#define MALL_ITEM_H

#include <string>

class Item {

public:
    // Constructor without parameters
    Item();

    // Init constructor
    Item(std::string name, unsigned int price);

    // Copy constructor
    Item(const Item& item);

    // Move constructor
    Item(Item&& item);

    /*
     * FUNCTIONALITY
     */

    // TODO: implement basic Item functionality
    /*
     *  - change price (if there is a discountCard)
     *  - return info
     *  - from production date to this day
     *  - calculate space of an object
     */

    /*
     * GETTERS AND SETTERS
     */

    // TODO: implement getters and setters


    /*
     * OPERATORS
     */

    // TODO: implement operators


    /*
     * GRAPHICS PART
     */

    void render();
    void update();


    // Destructor
    ~Item();

private:
    std::string name;
    // TODO: add brand
    // TODO: add pointer to Shop it belongs
    unsigned int price;
    // TODO: implement Date of production and expiration date
    // TODO: implement price array for amount of items
    std::string producer;

    unsigned int width;
    unsigned int height;

};


#endif //MALL_ITEM_H
