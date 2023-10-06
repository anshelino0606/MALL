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

    // Sort items by space they occupy
    std::vector<Item> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end(), Item::compareItems);

    // Initialize the cart and other variables
    std::vector<std::vector<Item>> cart;
    cart.push_back({}); // Start with the first row
    float currentRowWidth = 0.0f;
    float currentRowHeight = 0.0f;
    glm::vec2 currentPosition(0.0f, 0.0f);

    // Arrange items in rows and assign positions
    for (Item& item : sortedItems) {
        // Check if the item fits in the current row
        if (currentRowWidth + item.getWidth() <= width && currentRowHeight + item.getHeight() <= rowLimit) {
            // Place item in the current row and assign position
            item.pos = currentPosition;
            cart.back().push_back(item);

            // Update current position and row dimensions
            currentPosition.x += item.getWidth();
            currentRowWidth += item.getWidth();
            if (item.getHeight() > currentRowHeight)
                currentRowHeight = item.getHeight();
        } else {
            // Start a new row below, aligning with the end of the previous row
            cart.push_back({});
            currentPosition = glm::vec2(0.0f, currentPosition.y + currentRowHeight);
            currentRowWidth = item.getWidth();
            currentRowHeight = item.getHeight();

            // Place item in the new row and assign position
            item.pos = currentPosition;
            cart.back().push_back(item);
        }
    }

    return cart;

}






