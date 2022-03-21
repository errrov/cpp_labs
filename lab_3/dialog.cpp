#include "dialog.h"

namespace dialogue_menu{

    Train just_train;
    int number1;
    int tmp;
    int t[100];


    void menu_front() {
        std::cout << "Train manager : \n1)Add new vagon. \n2)Get quantity of passengers \n3)Reserve seats \n4)Passengers in specified vagon \n5)Remove vagons \n6)Get total number of passengers \n7)Input train information \n8)Exit " << std::endl;  
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
                just_train.Add_carriage_to_train();
                continue;

            case 2:
                just_train.Get_passenger_number(); //idk
                continue;

            case 3:
                int number;
                input::getNum(number,"Where to reserve: ");
                int qa;
                input::getNum(qa,"How much seats: ");
                just_train.Take_seats(number,qa);
                continue;

            case 4:
                int num;
                input::getNum(num, "Number of vagon: ");
                std::cout << just_train.Taken_in_carriage(num) << std::endl;
                continue;

            case 5:
                input::getNum(number1, "Enter quantity of vagons: ");
                std::cout << "Enter number of vagons you want to remove: ";
                for (int i=0; i<number1; i++) {
                    t[i] = input::getNum(tmp,"");
                }
                just_train.Remove_carriage(number1, t);
                continue;

            case 6:
                just_train.Get_passenger_number();
                continue;


            case 7:
                break;

            case 8:
                trigger = false;
                break;
        
            default:
                break;
            }
        }

    }
}

