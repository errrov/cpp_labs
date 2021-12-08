#include <iostream>
#include <vector>

namespace shop {
    
    class Product {
        protected:
        std::string product_name;
        std::size_t quantity_in_warehouse;
        std::string manufactured_country;

    }

    class Wholesale_product: public Product {

    }

    class Retail_product: public Product {
        
    }
    

    
}