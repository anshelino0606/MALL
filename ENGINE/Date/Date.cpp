//
// Created by Anhelina Modenko on 22.09.2023.
//

#include "Date.h"
#include <algorithm>
#include <iostream>

Date::Date(int year, int month, int day)
        : year(year), month(month), day(day) {}

int Date::getYear() const {
    return this->year;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getDay() const {
    return this->day;
}

Date::Date()  : year(0), month(0), day(0) {}

void swap(Date &first, Date &second) noexcept {
    using std::swap;
    swap(first.year, second.year);
    swap(first.month, second.month);
    swap(first.day, second.day);
}

Date::Date(const Date &other) : year(other.year), month(other.month), day(other.day) {}

Date::Date(Date &&other) noexcept : year(0), month(0), day(0) {
    swap(*this, other);
}

void Date::setYear(int year) {
    this->year = year;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setDay(int day) {
    this->day = day;
}

Date &Date::operator=(const Date &other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
    char delimiter;
    is >> date.year >> delimiter >> date.month >> delimiter >> date.day;
    return is;
}

void Date::loadFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    file >> *this;
}

bool Date::operator<(const Date &other) const {
    if (year < other.year)
        return true;
    else if (year == other.year) {
        if (month < other.month)
            return true;
        else if (month == other.month) {
            return day < other.day;
        }
    }
    return false;
}

bool Date::operator>(const Date &other) const {
    return other < *this;
}

bool Date::operator<=(const Date &other) const {
    return !(*this < other);
}

bool Date::operator>=(const Date &other) const {
    return !(*this > other);
}

bool Date::operator==(const Date &other) const {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date &other) const {
    return !(*this == other);
}