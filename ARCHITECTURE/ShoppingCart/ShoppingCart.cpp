//
// Created by Anhelina Modenko on 22.09.2023.
//

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
 : width(0), height(0), items(nullptr) {}

ShoppingCart::ShoppingCart(unsigned int width, unsigned int height, Item *items)
 : width(width), height(height), items(items) {}

ShoppingCart::ShoppingCart(const ShoppingCart &other) {

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

ShoppingCart::ShoppingCart(ShoppingCart&& shoppingCart) {

        maxCapacity = shoppingCart.maxCapacity;
        currentCapacity = shoppingCart.currentCapacity;

        if (shoppingCart.items != nullptr) {
            items = new Item[maxCapacity];
            for (int i = 0; i < currentCapacity; i++) {
                items[i] = shoppingCart.items[i];
            }
        } else {
            items = nullptr;
        }
        shoppingCart.maxCapacity = 0;
        shoppingCart.currentCapacity = 0;
        shoppingCart.items = nullptr;

}

void ShoppingCart::addToCart(const Item &item) {

    if (items == nullptr) {
        items = new Item[1];
        items[0] = item;
        currentCapacity++;
    } else {
        Item* temp = new Item[currentCapacity + 1];
        for (int i = 0; i < currentCapacity; i++) {
            temp[i] = items[i];
        }
        temp[currentCapacity] = item;
        delete[] items;
        items = temp;
        currentCapacity++;
    }

}

void ShoppingCart::removeFromCart(const Item &item) {

    if (items == nullptr) return;
    else {
        Item* temp = new Item[currentCapacity - 1];

        int j = 0;
        for (int i = 0; i < currentCapacity; i++) {
            if (items[i].getName() != item.getName()) {
                temp[j] = items[i];
                j++;
            }
        }
        delete[] items;
        items = temp;
        currentCapacity--;
    }

}

void ShoppingCart::printAllItems() {

    if (items == nullptr) return;
    else {
        for (int i = 0; i < currentCapacity; i++) {
            std::cout << items[i].getName() << std::endl;
        }
    }

}

float ShoppingCart::getHeightOfCart() {
    return height;
}

float ShoppingCart::getWidthOfCart() {
    return width;
}

Item* ShoppingCart::getItems() {
    return items;
}

void ShoppingCart::setHeightOfCart(float height) {
    this->height = height;
}

void ShoppingCart::setWidthOfCart(float width) {
    this->width = width;
}





