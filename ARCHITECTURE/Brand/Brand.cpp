//
// Created by Anhelina Modenko on 22.09.2023.
//

#include "Brand.h"


Brand::Brand()
    : name(""), country(""),
    description(""), adress("") {}

Brand::Brand(std::string name, std::string country, std::string description, std::string adress)
    : name(name), country(country),
    description(description), adress(adress) {}

Brand::Brand(const Brand &other) {
    this->name = other.name;
    this->country = other.country;
    this->description = other.description;
    this->adress = other.adress;
}

Brand::Brand(Brand &&other) noexcept {
    this->name = other.name;
    this->country = other.country;
    this->description = other.description;
    this->adress = other.adress;

    other.name = "";
    other.country = "";
    other.description = "";
    other.adress = "";
}

std::string Brand::getName() const {
    return name;
}

std::string Brand::getCountry() const {
    return country;
}

std::string Brand::getDescription() const {
    return description;
}

std::string Brand::getAdress() const {
    return adress;
}

void Brand::setName(const std::string &name) {
    Brand::name = name;
}

void Brand::setCountry(const std::string &country) {
    Brand::country = country;
}

void Brand::setDescription(const std::string &description) {
    Brand::description = description;
}

void Brand::setAdress(const std::string &adress) {
    Brand::adress = adress;
}

