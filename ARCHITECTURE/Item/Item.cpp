//
// Created by Anhelina Modenko on 22.09.2023.
//

#include "Item.h"

Item::Item()
    : name(""), producer(""),
    price(0), hasDiscountCard(false), discount(Discount::none),
    productionDate(Date(0,0,0)), expirationDate(Date(0,0,0)),
    width(0), height(0) {}


Item::Item(std::string name, std::string producer,
           unsigned int price, bool hasDiscountCard, Discount discount,
           Date productionDate, Date expirationDate,
           unsigned int width, unsigned int height)

           : name(name), producer(producer),
              price(price), hasDiscountCard(hasDiscountCard), discount(discount),
              productionDate(productionDate), expirationDate(expirationDate),
              width(width), height(height) {}


Item::Item(const Item &item) {

    this->name = item.name;
    this->producer = item.producer;
    this->price = item.price;
    this->hasDiscountCard = item.hasDiscountCard;
    this->discount = item.discount;
    this->productionDate = item.productionDate;
    this->expirationDate = item.expirationDate;
    this->width = item.width;
    this->height = item.height;

}

Item::Item(Item &&item) {

        this->name = item.name;
        this->producer = item.producer;
        this->price = item.price;
        this->hasDiscountCard = item.hasDiscountCard;
        this->discount = item.discount;
        this->productionDate = item.productionDate;
        this->expirationDate = item.expirationDate;
        this->width = item.width;
        this->height = item.height;

        item.name = "";
        item.producer = "";
        item.price = 0;
        item.hasDiscountCard = false;
        item.discount = Discount::none;
        item.productionDate = Date(0,0,0);
        item.expirationDate = Date(0,0,0);
        item.width = 0;
        item.height = 0;

}

bool Item::changePrice() {

    if (hasDiscountCard) {
        switch (discount) {
            case Discount::none:
                price *= 0.97;
                break;
            case Discount::three:
                price *= 0.95;
                break;
            case Discount::five:
                price *= 0.93;
                break;
            case Discount::seven:
                price *= 0.91;
                break;
        }
        return true;
    }
    return false;

}

std::string Item::getInfo() {

    std::string info = "";
    info += "Name: " + name + "\n";
    info += "Producer: " + producer + "\n";
    info += "Price: " + std::to_string(price) + "\n";
    info += "Has discount card: " + std::to_string(hasDiscountCard) + "\n";
    info += "Discount: " + std::to_string(static_cast<int>(discount)) + "\n";
    info += "Production date: " + productionDate.toString() + "\n";
    info += "Expiration date: " + expirationDate.toString() + "\n";
    info += "Width: " + std::to_string(width) + "\n";
    info += "Height: " + std::to_string(height) + "\n";
    return info;

}

std::ostream Item::writeInfoToFile() {

    std::ofstream file("item.txt");
    file << getInfo();
    file.close();

}

unsigned int Item::daysFromProduction() {

    time_t now = time(0);
    tm *ltm = localtime(&now);
    Date today(ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday);
    Date diff = today - productionDate;
    return diff.getYear() * 365 + diff.getMonth() * 30 + diff.getDay();

}

unsigned int Item::calculateSpace() {

    // TODO: implement handling different package sizes

    return width * height;

}

std::string Item::getName() const {
    return name;
}

unsigned int Item::getPrice() const {
    return price;
}

bool Item::getHasDiscountCard() const {
    return hasDiscountCard;
}

Discount Item::getDiscount() const {
    return discount;
}

std::string Item::getProducer() const {
    return producer;
}

unsigned int Item::getWidth() const {
    return width;
}

unsigned int Item::getHeight() const {
    return height;
}

Date Item::getProductionDate() const {
    return productionDate;
}

Date Item::getExpirationDate() const {
    return expirationDate;
}

void Item::setPrice(unsigned int price) {
    this->price = price;
}

void Item::setHasDiscountCard(bool hasDiscountCard) {
    this->hasDiscountCard = hasDiscountCard;
}

void Item::setDiscount(Discount discount) {
    this->discount = discount;
}

void Item::setExpirationDate(const Date &expirationDate) {
    this->expirationDate = expirationDate;
}

Item &Item::operator=(const Item &item) {

    if (this == &item) {
        return *this;
    }

    // Perform deep copy of Item members
    this->name = item.name;
    this->producer = item.producer;
    this->price = item.price;
    this->hasDiscountCard = item.hasDiscountCard;
    this->discount = item.discount;
    this->productionDate = item.productionDate;
    this->expirationDate = item.expirationDate;
    this->width = item.width;
    this->height = item.height;

    return *this;

}

bool Item::operator==(const Item &item) const {

    return this->name == item.name &&
           this->producer == item.producer &&
           this->price == item.price &&
           this->hasDiscountCard == item.hasDiscountCard &&
           this->discount == item.discount &&
           this->productionDate == item.productionDate &&
           this->expirationDate == item.expirationDate &&
           this->width == item.width &&
           this->height == item.height;

}

bool Item::operator!=(const Item &item) const {

    return !(*this == item);

}

bool Item::operator<(const Item &item) const {

    return this->price < item.price;

}

bool Item::operator>(const Item &item) const {

    return this->price > item.price;

}

bool Item::operator<=(const Item &item) const {

    return !(*this > item);

}

bool Item::operator>=(const Item &item) const {

    return !(*this < item);

}


std::ostream &operator<<(std::ostream &os, const Item &item) {

    os << item.name << " " << item.producer << " " << item.price << " " << item.hasDiscountCard << " " << static_cast<int>(item.discount) << " " << item.productionDate << " " << item.expirationDate << " " << item.width << " " << item.height;
    return os;

}

std::istream &operator>>(std::istream &is, Item &item) {

    is >> item.name >> item.producer >> item.price >> item.productionDate >> item.expirationDate >> item.width >> item.height;
    return is;

}












