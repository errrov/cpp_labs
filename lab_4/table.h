#include "Product.h"
#include "vector.h"
#pragma once
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
            table.push(prod);

            size++;
        }

        Product *find_by_id(std::string ID) {
            for(int i = 0; i < size; i++) {
                if (table[i] -> getID() == ID) {
                    return table[i];
                } 
            }
            return nullptr;
        }

        void print_by_index(int index) {
            std::cout << table[index] -> getID() << std::endl;
        }

        void delete_product(Product *prod) {
            table.delete_element(prod);
            size--;
        }

        void print_table () {
            for (int i = 0; i < size; i++) {
                print_by_index(i);
            }
        }
};

namespace input {
    template <class T>
    double getNum(T &a, const char* message = "") {
        std::cout << message;
        std::cin >> a;
        while (std::cin.fail()) {
            if (std::cin.eof()) {
                std::cout << "EOF !";
            }
            std::cout << "Enter valid value." << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> a;          
        }
        return a;
}
    template <class T>
    std::string getString(T &a, const char* message = "") {
        std::cout << message;
        std::cin >> a;
        while (std::cin.fail()) {
            if (std::cin.eof()) {
                std::cout << "EOF !";
            }
            std::cout << "Enter valid value: ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> a;          
        }
        return a;
    }
}

