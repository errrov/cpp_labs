#include <iostream>
#include "WholesaleProduct.h"


int Wholesale_product::make_a_sale(std::size_t quantity) {
    int profit = wholesale_size * unit_cost;
    return profit;
}

void Wholesale_product::change_cost(std::size_t cost) {
    unit_cost = cost;
};

void Wholesale_product::change_quantity(std::size_t quantity) {
    wholesale_size = quantity;
};



