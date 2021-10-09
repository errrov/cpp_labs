#include "structs.h"

namespace input {
    int getInt() {
        int input;
        std::cin >> input;
        while (std::cin.fail()) {
            if (std::cin.eof()) {
                std::cout << "EOF !";
            }
            std::cout << "Enter valid value." << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> input;          
        }
        return input;
    };  
}; 

namespace lab1 {
    Matrix::Matrix() {
        std::cout << "Enter height of Matrix: " << std::endl;
        height = input::getInt();
        std::cout << "Enter width of Matrix: " << std::endl;
        width = input::getInt();
    }

    void Matrix::input() {
        int inp = 0;
        Item *new_item;
        
        std::cout << "Enter values for Matrix:" << std::endl;
        for (int x=0; x < height; x++) {
            for (int y=0; y < width; y++) {
                inp = input::getInt();
                new_item = new Item;
                new_item -> x = x;
                new_item -> y = y;
                new_item -> value = inp;
                coordinates.push_back(new_item);
            }
        }
    }

    void Matrix::print_matrix_coordinates() {
        for (int i=0; i < coordinates.size(); ++i) {
            std::cout << "(" << coordinates[i] -> x + 1 << ":" << coordinates[i] -> y + 1<< ") =" << coordinates[i] -> value << std::endl; 
        }
    }

    void Matrix::print_matrix(){
        int current_position = 0;
        std::cout << "---------------------------------" << std::endl;
        for (int x=0; x < height; x++) {
            for (int y=0; y < width; y++) {
                std::cout << coordinates[current_position] -> value << " ";
                current_position++;
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    Matrix::~Matrix() {
        for (int i=0; i < coordinates.size(); i++) {
            delete coordinates[i];
        }
    }

    std::vector<double> Matrix::do_task() {
        int current_position = 0;
        double b=0.0;
        std::vector<double> result;

        for (int i=0; i < height; i++) {
            int sum = 0, min = 1000, max = 0;
            for (int j=0; j < width; j++) {
                sum += coordinates[current_position] -> value;
                if (coordinates[current_position] -> value < min) {
                    min = coordinates[current_position] -> value;
                }
                if (coordinates[current_position] -> value > max) {
                    max = coordinates[current_position] -> value;
                }
                current_position +=1;
            }
            b = (double)(sum - min)/(double)(max - min);
            result.push_back(b);
        }
        return result;
    }



}
