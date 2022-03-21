#include <iostream>
#include <algorithm>
#pragma once


class Product {
    protected:
        std::string ID;
        std::string product_name;
        std::string manufactured_country;

    public:
        Product() {
            product_name = "";
            manufactured_country = "";
        }

        Product(std::string id, std::string name, std::string country) {
            ID = std::move(id);
            product_name = std::move(name);
            manufactured_country = std::move(country);
        }
    
    std::string getID() {return ID;};
    Product* createProduct();
    //[[nodiscard]] std::string get_product_type {};
    bool operator<(const Product& p) const
    {
        return ID < p.ID;
    }
};








