//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_ITEM_H
#define MALL_ITEM_H

#include <string>
#include <time.h>
#include "../Date/Date.h"
#include "ENGINE/glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

enum class Discount {
    none = 0,
    three,
    five,
    seven
};

class Item {

public:
    /*
     * CONSTRUCTORS
     */

    // Constructor without parameters
    Item();

    // Init constructor
    Item(std::string name, std::string producer,
         unsigned int price, bool hasDiscountCard, Discount discount,
         Date productionDate, Date expirationDate,
         unsigned int width, unsigned int height, glm::vec2 pos);

    // Copy constructor
    Item(const Item& item);

    // Move constructor
    Item(Item&& item);


    /*
     * FUNCTIONALITY
     */

    /*
     *  - change price (if there is a discountCard)
     *  - return info
     *  - from production date to this day
     *  - calculate space of an object
     */

    bool changePrice();
    std::string getInfo();
    void writeInfoToFile(std::string filename);
    unsigned int daysFromProduction();
    unsigned int calculateSpace();


    /*
     * GETTERS AND SETTERS
     */

    std::string getName() const;
    unsigned int getPrice() const;
    bool getHasDiscountCard() const;
    Discount getDiscount() const;
    std::string getProducer() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    Date getProductionDate() const;
    Date getExpirationDate() const;

    void setPrice(unsigned int price);
    void setHasDiscountCard(bool hasDiscountCard);
    void setDiscount(Discount discount);
    void setExpirationDate(const Date& expirationDate);
    void setName(std::string name);
    void setProducer(std::string producer);

    static bool compareItems(const Item& a, const Item& b);

    /*
     * OPERATORS
     */

    Item& operator=(const Item& item);
    bool operator==(const Item& item) const;
    bool operator!=(const Item& item) const;
    bool operator<(const Item& item) const;
    bool operator>(const Item& item) const;
    bool operator<=(const Item& item) const;
    bool operator>=(const Item& item) const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend std::istream& operator>>(std::istream& is, Item& item);

    /*
     * GRAPHICS PART
     */

    void render();
    void update();
    glm::vec2 pos;


    // Destructor
    ~Item() = default;

    unsigned int width;
private:

    std::string name;
    std::string producer;

    // TODO: add brand
    // TODO: add pointer to Shop it belongs

    unsigned int price;
    // TODO: implement price array for amount of items
    bool hasDiscountCard;
    Discount discount;

    Date productionDate;
    Date expirationDate;

    unsigned int height;

};


#endif //MALL_ITEM_H
