#ifndef structs_h
#define structs_h

#include <iostream>
#include <cmath>

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
}

namespace lab2 {
    //x^3 + y^3 = nxy.
    class Descartes_list {
        public:

        double return_square_size();

        double center_distance();

        double vertex_radius_of_curvature();

        double knot_radius_of_curvature();

        double loop_area();

        double diameter_value();

        double diameter_distance();

        double get_n() {return n;}
        
        double get_angle() {return angle;}

        void change_n(double a);

        Descartes_list();

        Descartes_list(double a);

        Descartes_list(double a, double ang);

        private:

        double n;
        double angle;

    };

}

#endif