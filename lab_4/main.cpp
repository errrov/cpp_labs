#include <iostream>
#include "classes.h"

using namespace shop;

int main() {
    auto *Product_A = new Retail_product(12,10, "A15", "banana", 100, "Africa");
    auto *Product_B = new Retail_product(13,11, "A16", "dildo", 50, "Dagestan");
    Table main_table;
    main_table.add_product(Product_A);
    main_table.add_product(Product_B);                                        
    main_table.print_table();
    return 0;
}