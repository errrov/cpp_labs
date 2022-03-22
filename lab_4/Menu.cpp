#include <iostream>
#include "Menu.h"

namespace dialogue_menu{

    Table Shop_table;
    int number1;
    int tmp;
    int t[100];


    void menu_front() {
        std::cout << "-------------------------------------------------------\n";
        std::cout << "Product manager: \n1)Add new  product: \n2)Get product info: \n3)Find product by id: \n4)Get product quantity: \n5)Make a retail product sale: \n6)Make a whole product sale: \n7)Change product quantity: \n8)Change product price: \n9)Change retail product allowance: \n10)Change wholesale product something: \n11)Delete product by ID: \n13)To print table \n14)To quit" << std::endl;  
    }

     void menu_back() {
        bool trigger = true;

        while (trigger) {
            menu_front();
            int tae;
            Wholesale_product tmp_wh;
            int tmp1,tmp2, tmpx, tmpz;
            std::string tmp3,tmp4,tmp5;
            int product_type;
            std::cin >> tae;
            switch (tae)
            {
            case 1:
                std::cout << "-------------------------------------------------------\n";
                std::cout << "What king of product you want?\n1.Wholesale \n2.Retail" << std::endl;
                std::cin >> product_type;
                if (product_type == 1) {
                    input::getNum(tmp1,"Input size of wholesale product: ");
                    input::getNum(tmp2,"Input unit cost of wholesale product: ");
                    input::getNum(tmpz, "Input quantity of product: ");
                    input::getString(tmp3, "Input product ID: ");
                    input::getString(tmp4, "Input product name: ");
                    input::getString(tmp5, "Input product county: ");
                    auto *Wholesale_prod =  new Wholesale_product(tmp1,tmp2,tmp3,tmp4,tmp5, tmpz);
                    Shop_table.add_product(Wholesale_prod);
                    Shop_table.add_wholesale_product(Wholesale_prod);
                    Wholesale_prod->get_product_info();

                }
                if (product_type == 2) {
                    input::getNum(tmp1,"Input size of retail product: ");
                    input::getNum(tmp2,"Input  cost of retail product: ");
                    input::getNum(tmpx,"Input value of allowance: ");
                    input::getString(tmp3, "Input product ID: ");
                    input::getString(tmp4, "Input product name: ");
                    input::getString(tmp5, "Input product county: ");
                    auto *Retail_prod =  new Retail_product(tmpx,tmp2,tmp1,tmp3,tmp4,tmp5);
                    Shop_table.add_product(Retail_prod);
                    Shop_table.add_retail_product(Retail_prod);
                    Retail_prod->get_product_info();

                }
                continue;

            case 2:
                input::getString(tmp3, "Enter ID of product: ");
                if(Shop_table.find_product_by_id(tmp3) != nullptr) {
                std::cout << Shop_table.find_product_by_id(tmp3)->getClassification() << " ";
                if (Shop_table.find_product_by_id(tmp3)->getClassification() == "Wholesale") {
                    Shop_table.find_wholesale_by_id(tmp3)->get_product_info();
                }
                if (Shop_table.find_product_by_id(tmp3)->getClassification() == "Retail") {
                    Shop_table.find_retail_by_id(tmp3)->get_product_info();
                }
                }
                continue;

            case 3:
                input::getString(tmp3, "Enter ID of product: ");
                if(Shop_table.find_product_by_id(tmp3) != nullptr){
                std::cout << Shop_table.find_product_by_id(tmp3)->getClassification() << " ";
                if (Shop_table.find_product_by_id(tmp3)->getClassification() == "Wholesale") {
                    Shop_table.find_wholesale_by_id(tmp3)->get_product_info();
                }
                if (Shop_table.find_product_by_id(tmp3)->getClassification() == "Retail") {
                    Shop_table.find_retail_by_id(tmp3)->get_product_info();
                }
                }
                continue;

            case 4:
                input::getString(tmp3, "Enter ID of product: ");
                if (Shop_table.find_product_by_id(tmp3) != nullptr){
                std::cout << Shop_table.find_product_by_id(tmp3)->getQuantity() << std::endl;
                }
                continue;

            case 5:
                input::getString(tmp3, "Enter ID of product: ");
                input::getNum(tmp1, "Enter quantity of product to sell: ");
                if(Shop_table.find_retail_by_id(tmp3) != nullptr) {
                    Shop_table.find_retail_by_id(tmp3)->get_product_info();
                    
                    if (Shop_table.find_retail_by_id(tmp3)->make_a_sale(tmp1)==1){continue;}
                    std::cout << "Money: " << Shop_table.find_retail_by_id(tmp3)->make_a_sale(tmp1) << std::endl;
                    continue;
                }
                std::cout << "No such ID " << std::endl;
                continue;

            case 6:

            case 7:
                input::getString(tmp3, "Enter ID of product: ");
                input::getNum(tmp1, "Enter new quantity: ");
                Shop_table.find_product_by_id(tmp3)->changeQuantity(tmp1);


            case 13:
                Shop_table.print_table();
                continue;
            case 14:
                trigger = false;
                break;
        
            default:
                break;
            }
        }
     }

    
}