//
// Created by Anhelina Modenko on 22.09.2023.
//

#include <sstream>
#include "Shop.h"

Shop::Shop()
    : maxCapacity(), currentCapacity(), items() {}

Shop::Shop(unsigned int height, unsigned int width, Texture2D tex, const std::string& name, unsigned int maxCapacity, Item* items)
    : maxCapacity(maxCapacity), currentCapacity(0), items(items), name(name), height(height), width(width), tex(tex) {

    this->maxCapacity = maxCapacity > 0 ? maxCapacity : 0;
    this->currentCapacity = currentCapacity > 0 ? currentCapacity : 0;
    this->name = name != "" ? name : "";

    if (items != nullptr) {

        this->items = new Item[this->maxCapacity];

        for (int i = 0; i < this->currentCapacity; i++) {
            items[i].setName(items[i].getName());
            items[i].setPrice(items[i].getPrice());
            items[i].setProducer(items[i].getProducer());
            items[i].setExpirationDate(items[i].getExpirationDate());
            items[i].setDiscount(items[i].getDiscount());
            items[i].setHasDiscountCard(items[i].getHasDiscountCard());

        }
    }
}

Shop::Shop(const Shop& other) {

    maxCapacity = other.maxCapacity;
    currentCapacity = other.currentCapacity;

    if (other.items != nullptr) {

        items = new Item[maxCapacity];

        for (int i = 0; i < currentCapacity; i++) {
            items[i] = other.items[i];
        }
    } else {

        items = nullptr;

    }



}

Shop::Shop(Shop&& other) noexcept {

    maxCapacity = other.maxCapacity;
    currentCapacity = other.currentCapacity;

    if (other.items != nullptr) {

        items = new Item[maxCapacity];

        for (int i = 0; i < currentCapacity; i++) {
            items[i] = other.items[i];
        }
    } else {

        items = nullptr;

    }

    other.maxCapacity = 0;
    other.currentCapacity = 0;
    other.items = nullptr;

}


unsigned int Shop::getMaxCapacity() const {
        return maxCapacity;
}

unsigned int Shop::getCurrentCapacity() const {
        return currentCapacity;
}

Item* Shop::getItems() const {
        return items;
}

std::string Shop::getName() const {
        return name;
}

void Shop::setMaxCapacity(unsigned int maxCapacity) {
        this->maxCapacity = maxCapacity;
}

void Shop::setCurrentCapacity(unsigned int currentCapacity) {
        this->currentCapacity = currentCapacity;
}

void Shop::setItems(Item* items) {
        this->items = items;
}

void Shop::setName(const std::string& name) {
        this->name = name;
}



Shop::~Shop() {

    delete[] items;

}

void Shop::readFromFile(const std::string &fileName) {

    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "ERROR::FILE DIDN'T OPEN " << fileName << std::endl;
        return;
    }

    try {
        std::string line;
        std::getline(file, line);

        int numLines = 0;

        while (std::getline(file, line)) {
            numLines++;
        }

        file.clear();
        file.seekg(0);

        items = new Item[numLines];

        int itemIndex = 0;

        while (std::getline(file, line)) {

            std::istringstream iss(line);
            std::string token;

            std::string name;
            std::string producer;
            int day, month, year;
            double price;
            bool hasDiscountCard;

            if (std::getline(iss, token, ',')) {
                name = token;
            }

            if (std::getline(iss, token, ',')) {
                producer = token;
            }

            if (std::getline(iss, token, ',')) {
                price = std::stod(token);
            }

            if (std::getline(iss, token, ',')) {
                day = std::stoi(token);
            }

            if (std::getline(iss, token, '-')) {
                month = std::stoi(token);
            }

            if (std::getline(iss, token, '-')) {
                year = std::stoi(token);
            }


            items[itemIndex++].setExpirationDate(Date(day, month, year));
            items[itemIndex++].setHasDiscountCard(hasDiscountCard);
            items[itemIndex++].setName(name);
            items[itemIndex++].setPrice(price);
            items[itemIndex++].setProducer(producer);


        }

        } catch (const std::exception& e) {
            std::cerr << "ERROR::ROOM DIDN'T LOAD FROM FILE " << e.what() << std::endl;
    }


}

void Shop::print() const {

    std::cout << "Shop name: " << name << std::endl;
    std::cout << "Max capacity: " << maxCapacity << std::endl;
    std::cout << "Current capacity: " << currentCapacity << std::endl;
    std::cout << "Items: " << std::endl;

    for (int i = 0; i < currentCapacity; i++) {
        items[i].getInfo();
    }

}

void Shop::print(std::ostream& os) const {

    os << "Shop name: " << name << std::endl;
    os << "Max capacity: " << maxCapacity << std::endl;
    os << "Current capacity: " << currentCapacity << std::endl;
    os << "Items: " << std::endl;

    for (int i = 0; i < currentCapacity; i++) {
        items[i].getInfo();
    }

}


void Shop::merge(const Shop& other) {
    this->name = other.name;
    this->maxCapacity = other.maxCapacity;
    this->currentCapacity = other.currentCapacity;

    // Assuming Item has a copy assignment operator
    delete[] this->items;
    this->items = new Item[this->maxCapacity];
    for (unsigned int i = 0; i < this->currentCapacity; ++i) {
        this->items[i] = other.items[i];
    }
}

Shop::Shop(const Shop &first, const Shop &second) {
    
    this->name = first.name + " & " + second.name;
    this->maxCapacity = first.maxCapacity + second.maxCapacity;
    this->currentCapacity = first.currentCapacity + second.currentCapacity;

    this->items = new Item[this->maxCapacity];
    for (unsigned int i = 0; i < first.currentCapacity; ++i) {
        this->items[i] = first.items[i];
    }
    for (unsigned int i = 0; i < second.currentCapacity + first.currentCapacity; ++i) {
        this->items[i + first.currentCapacity] = second.items[i];
    }

}

Shop *Shop::mergeIntoAnotherShop(const Shop &other) {
    Shop* newShop = new Shop(*this, other);
    return newShop;
}

Shop &Shop::operator=(const Shop &other) {
    // merge one shop into another
    this->name = other.name;
    this->maxCapacity = other.maxCapacity;
    this->currentCapacity = other.currentCapacity;

    // Assuming Item has a copy assignment operator
    delete[] this->items;
    this->items = new Item[this->maxCapacity];
    for (unsigned int i = 0; i < this->currentCapacity; ++i) {
        this->items[i] = other.items[i];
    }
    return *this;
}

void Shop::printAllItems() const {

        for (int i = 0; i < currentCapacity; i++) {
            items[i].getInfo();
        }

}


void Shop::processInput(float dt) {

}
void Shop::render() {

}
void Shop::init() {

}
void Shop::update(float dt) {

}
void Shop::doCollisions() {

}

std::ostream& operator<<(std::ostream& os, const Shop& shop) {
    shop.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Shop& shop) {
    std::string name;
    unsigned int maxCapacity;
    unsigned int currentCapacity;

    is >> name >> maxCapacity >> currentCapacity;

    shop.setName(name);
    shop.setMaxCapacity(maxCapacity);
    shop.setCurrentCapacity(currentCapacity);

    return is;
}