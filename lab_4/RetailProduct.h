#include "Product.h"
#pragma once


class Retail_product : public Product {
    private:
        std::size_t unit_cost;
        std::size_t allowance;
        std::size_t quantity;

    public:

        Retail_product() : Product() {

            allowance = 0;
            unit_cost = 0;
            quantity = 0;
        }

        Retail_product(int allowance, int cost, int size, std::string id, std::string name, std::string country) : Product(std::move(id), std::move(name), std::move(country)) {
            if (allowance >=0) {
                allowance = allowance;
            } else {
                allowance = 0;
            }
            if (cost >=0) {
                unit_cost = cost;
            } else { 
                unit_cost = 0 ;
            }
            if (size >=0) {
                quantity = size;
            } else {
                quantity = 0;
            }
        }

        int make_a_sale(std::size_t quantity);
        void add_to_Warehouse(std::size_t extra_quantity);
        void change_cost(std::size_t cost);
        void get_product_info(){std::cout << "ID: " << ID << " Product name: " << product_name  << " County: " << manufactured_country << " Quantity: " << quantity << std::endl;};

        void change_allowance(std::size_t quantity);


    
    };