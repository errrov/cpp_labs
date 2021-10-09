#ifndef structs_h
#define structs_h

#include <iostream>
#include <vector>

namespace lab1 {

struct Item {
    int x;
    int y;
    int value;
};

class Matrix {
    public:
        void input();

        void print_matrix_coordinates();

        void print_matrix();
        
        ~Matrix();

        std::vector<double> do_task();

        Matrix();

    private:
        int height, width;
        std::vector<Item *> coordinates;
};
};
#endif