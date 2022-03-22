#include "Product.h"
#pragma once


class Wholesale_product : public Product {
    private:
        std::size_t wholesale_size;
        std::size_t unit_cost;

    public:

        Wholesale_product() : Product() {
            wholesale_size = 0;
            unit_cost = 0;
        }

        Wholesale_product(int size, int cost, std::string id, std::string name, std::string country, int quantity) : Product(std::move(id), std::move(name), std::move(country),quantity) {
            if (size >=0) {
                wholesale_size = size;
            } else {
                wholesale_size = 0;
            }
            if (cost >=0) {
                unit_cost = cost;
            } else { 
                unit_cost = 0 ;
            }
            classification = "Wholesale";
            Product::quantity = wholesale_size;
        }

        int price(){return unit_cost;};
        int quantity(){return wholesale_size;};
        int make_a_sale(std::size_t quantity);
        void add_to_Warehouse(std::size_t extra_quantity);
        void changePrice(int new_price) {unit_cost = new_price;};
        virtual void get_product_info(){std::cout << "ID: " << ID << " Product name: " << product_name  << " County: " << manufactured_country << " Quantity: " << Product::quantity << " Wholesale size: " << wholesale_size << std::endl;};
        std::string get_product_type() {return "Wholesale";};
        void change_quantity(std::size_t wholesale_size);

    //void operator=(Retail_product prod);




};