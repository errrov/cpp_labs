#include <iostream>
#include "RetailProduct.h"

int Retail_product::make_a_sale(std::size_t quant) {
    int profit = quant * unit_cost * allowance;
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