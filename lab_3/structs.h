#include <iostream>
#include <vector>
#pragma once


struct Carriage
{
    int total_place;
    int taken_place;
    struct Carriage *next;
    int index;
};


    
class Train
{
private:
    struct Carriage* loco;

    std::vector<Carriage*> vagons;
    struct Carriage* create_new_vagon(int a);
    struct Carriage* create_loco();


public:
    Train();
    Train_input();
    Taken_in_carriage(int number);
    Take_seats(int carriage_number, int number_of_taken_places);
    Add_carriage_to_train();
    Remove_carriage(int quantity, int* t);
    Get_passenger_number();

    print();
    ~Train();
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
}
    
