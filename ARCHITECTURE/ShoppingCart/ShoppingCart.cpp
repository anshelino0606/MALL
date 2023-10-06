//
// Created by Anhelina Modenko on 22.09.2023.
//

#include "ShoppingCart.h"
#include <algorithm>

ShoppingCart::ShoppingCart()
 : width(0), height(0), items(nullptr) {}

ShoppingCart::ShoppingCart(unsigned int width, unsigned int height, Texture2D tex ,Item *items)
 : width(width), height(height), items(items), tex(tex) {}

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

std::vector<Item> ShoppingCart::getItemsVec() {
    // return vector of items
    std::vector<Item> itemsVec;
    for (int i = 0; i < currentCapacity; i++) {
        itemsVec.push_back(items[i]);
    }
    return itemsVec;
}

void ShoppingCart::render() {

}

void ShoppingCart::init() {

}

void ShoppingCart::update(float dt) {

}

std::vector<std::vector<Item>> ShoppingCart::calculateOptimalPlacement(const std::vector<Item> &items, float rowLimit) {

    std::vector<Item> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end(), Item::compareItems);

    std::vector<std::vector<Item>> cart;
    cart.push_back({});
    float currentRowWidth = 0.0f;
    float currentRowHeight = 0.0f;

    for (const Item& item : sortedItems) {
        // Check if the item fits in the current row
        if (currentRowWidth + item.width <= this->width && currentRowHeight + item.getHeight() <= rowLimit) {
            cart.back().push_back(item); // Place item in the current row
            currentRowWidth += item.width;
            if (item.getHeight() > currentRowHeight)
                currentRowHeight = item.getHeight();
        } else {
            // Start a new row at the end of the cart
            cart.push_back({});
            cart.back().push_back(item);
            currentRowWidth = item.getWidth();
            currentRowHeight = item.getHeight();
        }
    }
    return cart;


}






