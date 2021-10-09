#include "dialog.h"

namespace dialogue_menu{

    void menu_front() {
        std::cout << "Menu for x^3 + y^3 = nxy : \n1)Get square site. \n2)Get radius of curvature in vertex. \n3)Get radius of curvature in knot. \n4)Get diameter value. \n5)Get diameter distance. \n6)Center distance in polar coordinates. \n7)Exit program " << std::endl;  
    }

    void menu_back() {
        bool trigger = true;

        while (trigger) {
            menu_front();
            int choice;
            input::getNum(choice,"Enter menu choice: ");
            switch (choice)
            {
            case 1:
                menu_square_site();
                continue;

            case 2:
                menu_vertex_curvature();
                continue;

            case 3:
                menu_knot_curvature();
                continue;

            case 4:
                menu_diameter_value();
                continue;

            case 5:
                menu_diameter_distance();
                continue;

            case 6:
                menu_center_distance();
                continue;


            case 7:
                trigger = false;
                break;
        
            default:
                break;
            }
        }

    }

    void menu_square_site() {
        std::cout << "------------------------------------" << std::endl;
        double number;
        number = input::getNum(number, "Enter value of n: ");
        lab2::Descartes_list list(number);
        std::cout << list.return_square_size() << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
    
    void menu_vertex_curvature() {
        std::cout << "------------------------------------" << std::endl;
        double number;
        number = input::getNum(number, "Enter value of n: ");
        lab2::Descartes_list list(number);
        std::cout << list.vertex_radius_of_curvature() << std::endl;
        std::cout << "------------------------------------" << std::endl;

    }

    void menu_knot_curvature() {
        std::cout << "------------------------------------" << std::endl;
        double number;
        number = input::getNum(number, "Enter value of n: ");
        lab2::Descartes_list list(number);
        std::cout << list.knot_radius_of_curvature() << std::endl;
        std::cout << "------------------------------------" << std::endl;

    }

    void menu_diameter_value() {
        std::cout << "------------------------------------" << std::endl;
        double number;
        number = input::getNum(number, "Enter value of n: ");
        lab2::Descartes_list list(number);
        std::cout << list.diameter_value() << std::endl;
        std::cout << "------------------------------------" << std::endl;

    }

    void menu_diameter_distance() {
        std::cout << "------------------------------------" << std::endl;
        double number;
        number = input::getNum(number, "Enter value of n: ");
        lab2::Descartes_list list(number);
        std::cout << list.diameter_distance() << std::endl;
        std::cout << "------------------------------------" << std::endl;
   
    }

    void menu_center_distance() {
        std::cout << "------------------------------------" << std::endl;
        double number, angle;
        number = input::getNum(number, "Enter value of n: ");
        angle = input::getNum(angle, "Enter value of angle: ");
        lab2::Descartes_list list(number,angle);
        std::cout << list.diameter_distance() << std::endl;
        std::cout << "------------------------------------" << std::endl;
   
    }

    

}