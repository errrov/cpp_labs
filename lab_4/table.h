#include "classes.h"
#pragma once

using namespace shop;
class Table {
    private:
        int size;
        Vector::NewVector<Product*> table;

    public:
        Table() : size(0) {}
        ~Table() = default;

        void setSize(int new_size) {
            if (new_size < 0) {
                new_size = 0;
                throw std::out_of_range("Size cant be negative ! ");
            }
            size = new_size;
        }

        void add_product(Product *prod) {
            for(int i=0; i<size; i++) {
                if (prod -> getID() < table[i] ->getID()) {

                }
            }
            table.push(prod);

            size++;
        }

        Product *find_by_id(std::string ID) {
            for(int i = 0; i < size; i++) {
                if (table[i] -> getID() == ID) {
                std::cout << "Success!" << std::endl;
                    return table[i];
                } 
            }
            return nullptr;
        }

        void print_by_index(int index) {
            std::cout << table[index] -> getID() << std::endl;
        }

        void delete_product(std::string ID) {
            table.delete_element(find_by_id(ID));
            size--;
        }

        void print_table () {
            for (int i = 0; i < size; i++) {
                print_by_index(i);
            }
        }
};
