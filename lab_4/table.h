#include "Product.h"
#include "WholesaleProduct.h"
#include "RetailProduct.h"
#include "vector.h"
#pragma once
class Table {

    private:
        int size;
        Vector::NewVector<Product*> table;
        Vector::NewVector<Wholesale_product*> table_wholesale;
        Vector::NewVector<Retail_product*> table_retail;

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

        void add_wholesale_product(Wholesale_product* prod){
            table_wholesale.push(prod);
        }


        void add_retail_product(Retail_product* prod) {
            table_retail.push(prod);
        }

        Product *find_product_by_id(std::string ID) {
            for(int i = 0; i < size; i++) {
                if (table[i] -> getID() == ID) {
                    std::cout << "Success! \n";
                    return table[i];
                } 
            }
            std::cout << "Failure! \n";
            return nullptr;
        }

        Wholesale_product *find_wholesale_by_id(std::string ID){
            for(int i = 0; i < size; i++) {
                if (table_wholesale[i] -> getID() == ID) {
                    std::cout << "Success! \n";
                    return table_wholesale[i];
                } 
            }
            std::cout << "Failure! \n";
            return nullptr;
        }

        Retail_product *find_retail_by_id(std::string ID){
            for(int i = 0; i < size; i++) {
                if (table_retail[i] -> getID() == ID) {
                    std::cout << "Success! \n";
                    return table_retail[i];
                } 
            }
            std::cout << "Failure! \n";
            return nullptr;
        }


       /* Wholesale_product *find_wholesale_product_by_id(std::string ID) {
            for(int i = 0; i < table_wholesale.current; i++) {
                if (table_wholesale[i] -> getID() == ID) {
                    std::cout << "Success! \n";
                    return table_wholesale[i];
                } 
            }
            std::cout << "Failure! \n";
            return nullptr; 
        }

        Retail_product *find_retail_product_by_id(std::string ID) {
            for(int i = 0; i < size; i++) {
                if (table_retail[i] -> getID() == ID) {
                    std::cout << "Success! \n";
                    return table_wholesale[i];
                } 
            }
            std::cout << "Failure! \n";
            return nullptr; 
        }*/

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

