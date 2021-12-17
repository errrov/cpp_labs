#include <iostream>
#include <vector>
#include "vector.h"

namespace shop {
    
    
    class Product {
        protected:
            std::string ID;
            std::string product_name;
            std::size_t quantity_in_warehouse;
            std::string manufactured_country;

        public:
            Product() {
                product_name = "";
                quantity_in_warehouse = 0;
                manufactured_country = "";
            }

            Product(std::string id, std::string name, int quantity, std::string country) {
                ID = std::move(id);
                product_name = std::move(name);
                if (quantity >= 0) {
                    quantity_in_warehouse = quantity;
                } else {
                    quantity = 0;
                }
                manufactured_country = std::move(country);
            }
        
        std::string getID() {return ID;};
        //[[nodiscard]] std::get_product_info ???
        //[[nodiscard]] std::string get_product_type {}; 
        std::size_t getProductQuantity() {return quantity_in_warehouse;};
    };

    class Wholesale_product : public Product {
        private:
            std::size_t wholesale_size;
            std::size_t unit_cost;

        public:

            Wholesale_product() : Product() {
                wholesale_size = 0;
                unit_cost = 0;
            }

            Wholesale_product(int size, int cost, std::string id, std::string name, int quantity, std::string country) : Product(std::move(id), std::move(name), quantity, std::move(country)) {
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
            }

            void make_a_sale(std::size_t quantity);
            void add_to_Warehouse(std::size_t extra_quantity);
            void change_cost(std::size_t cost);
            void change_quantity(std::size_t quantity);

        //void operator=(Retail_product prod);




    };

    class Retail_product : public Product {
        private:
            std::size_t unit_cost;
            std::size_t allowance;

        public:

            Retail_product() : Product() {
                allowance = 0;
                unit_cost = 0;
            }

            Retail_product(int allowance, int cost, std::string id, std::string name, int quantity, std::string country) : Product(std::move(id), std::move(name), quantity, std::move(country)) {
                if (allowance >=0) {
                    allowance = allowance;
                } else {
                    allowance = 0;
                }
                if (cost >=0) {
                    unit_cost = cost;
                } else { 
                    unit_cost = 0 ;
                }
            }

            void make_a_sale(std::size_t quantity);
            void add_to_Warehouse(std::size_t extra_quantity);
            void change_cost(std::size_t cost);
            void change_allowance(std::size_t quantity);

            void operator=(Wholesale_product prod);

        
        };

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
    

    
}