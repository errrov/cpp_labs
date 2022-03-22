#include <iostream>
#include <algorithm>
#pragma once


class Product {
    protected:
        std::string ID;
        std::string classification;
        std::string product_name;
        std::string manufactured_country;
        int quantity;

    public:
        Product() {
            product_name = "";
            manufactured_country = "";
            classification = "";
        }

        Product(std::string id, std::string name, std::string country, int quantity) {
            ID = std::move(id);
            product_name = std::move(name);
            manufactured_country = std::move(country);
            classification = "Product";

        }
    
    std::string getID() {return ID;};
    int getQuantity() {return quantity;};
    void changeQuantity(int quant);
    Product* createProduct();
    std::string getClassification() {return classification;};
    virtual void get_product_info() {std::cout << "ID: " << ID << "Product name: " << product_name << "Manufacture_country: " << manufactured_country << "Price" << std::endl;};
    //[[nodiscard]] std::string get_product_type {};
    bool operator<(const Product& p) const
    {
        return ID < p.ID;
    }
};








