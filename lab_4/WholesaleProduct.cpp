#include <iostream>
#include "WholesaleProduct.h"


int Wholesale_product::make_a_sale(std::size_t quant) {
    if(quant > Product::quantity) {
        std::cout << "you want to sell more that in warehouse!" << std::endl;
        return 1;
    }
    int profit = wholesale_size * unit_cost;
    Product::quantity -= quant;
    return profit;
}

void Wholesale_product::change_quantity(std::size_t quantity) {
    wholesale_size = quantity;
};



