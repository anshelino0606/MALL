//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef ENGINE_MALL_DATE_H
#define ENGINE_MALL_DATE_H

#include <fstream>

class Date {
// Default constructor
    Date();

    // Parameterized constructor
    Date(int year, int month, int day);

    // Copy constructor
    Date(const Date& other);

    // Move constructor
    Date(Date&& other) noexcept;

    // load from file
    void loadFromFile(const std::string& fileName);

    // Easily moving objects
    friend void swap(Date& first, Date& second) noexcept;

    // operator of copy
    Date& operator=(const Date& other);

    // operators of streams
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    friend std::istream& operator>>(std::istream& is, Date& date);

    // overloading
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;

    // Destructor
    ~Date() = default;

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

private:
    int year;
    int month;
    int day;
};


#endif //ENGINE_MALL_DATE_H
