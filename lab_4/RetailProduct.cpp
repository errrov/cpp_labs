#include <iostream>
#include "RetailProduct.h"

int Retail_product::make_a_sale(std::size_t quant) {
    if(quant > quantity) {
        std::cout << "You want to sell more than expected! " << std::endl;
        return 1;
    }
    int profit = allowance * unit_cost * quant;
    quantity = quantity - quant;
    return profit;
}

void Retail_product::add_to_Warehouse(std::size_t number) {
    quantity +=number;
}

void Retail_product::change_cost(std::size_t new_price) {
    unit_cost = new_price;
}

void Retail_product::change_allowance(std::size_t new_allowance) {
    allowance = new_allowance;
}