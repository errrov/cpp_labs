#include <iostream>

#include "structs.h"

int main() {
    int height = 0, width = 0; 
    lab1::Matrix *matrix = new lab1::Matrix;
    std::vector<double> result;

    matrix -> input();
    std::cout << "Matrix is : \n";
    matrix -> print_matrix();
    result = matrix ->do_task();

    std::cout << "Vector is : ";
    for (int i=0; i<result.size(); i++) {
        std::cout << result[i] << " ";
    }

    delete matrix;
    return 0;
}

