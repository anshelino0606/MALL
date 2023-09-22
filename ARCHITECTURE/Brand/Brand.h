//
// Created by Anhelina Modenko on 22.09.2023.
//

#ifndef MALL_BRAND_H
#define MALL_BRAND_H

#include <string>

class Brand {
public:

    /*
     * CONSTRUCTORS
     */

    // Without parameters
    Brand();

    // Init constructor
    Brand(std::string name, std::string country, std::string description, std::string adress);

    // Copy constructor
    Brand(const Brand& other);

    // Move constructor
    Brand(Brand&& other) noexcept;

    /*
     * GETTERS AMD SETTERS
     */

    std::string getName() const;
    std::string getCountry() const;
    std::string getDescription() const;
    std::string getAdress() const;

    void setName(const std::string& name);
    void setCountry(const std::string& country);
    void setDescription(const std::string& description);
    void setAdress(const std::string& adress);

private:
    std::string name;
    std::string country;
    std::string description;
    std::string adress;

};


#endif //MALL_BRAND_H
