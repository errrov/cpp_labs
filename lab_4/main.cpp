#include <iostream>
#include "classes.h"

using namespace shop;

int main() {
    auto *Product_A = new Retail_product(12,10, "A15", "banana", 100, "Africa");
    auto *Product_B = new Retail_product(13,11, "A16", "qwert", 50, "Chaet republic");
    auto *Product_C = new Retail_product(12,10, "A17", "banana", 100, "Africa");
    Table main_table;
    main_table.add_product(Product_A);
    main_table.add_product(Product_B);
    main_table.add_product(Product_C);                                           
    main_table.print_table();
    main_table.find_by_id("A15");
    main_table.delete_product(main_table.find_by_id("A16"));
    main_table.print_table();
    return 0;
}