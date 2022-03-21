#include "structs.h"    

Train::Train() {
    this->loco = create_loco(); 
    }

Train::print() {
    std::cout << loco->index <<std::endl;
    while (loco->next!=nullptr) {
        loco = loco->next;
        std::cout << "\nAAA" <<loco->index << loco->taken_place << loco->total_place <<std::endl;

    }
}

struct Carriage* Train::create_loco() {
    struct Carriage* vagon = new struct Carriage;
    int b,c;
    vagon ->taken_place =0;
    vagon ->total_place =0;
    vagon->index = 1;
    vagon->next = nullptr;
    return vagon;    
}

struct Carriage* Train::create_new_vagon(int a) {
    struct Carriage* vagon = new struct Carriage;
    int b,c;
    while(true){
    input::getNum(b,"Number of taken seats: ");
    vagon ->taken_place=b;
    input::getNum(c, "Number of total seats: ");
    if(c>=b){
    vagon->total_place = c;
    vagon->index = a;
    vagon->next = nullptr;
    return vagon; 
    }
    else {std::cout << "Taken seats value is higher that total seats!" << std::endl;}

}
}



Train::Taken_in_carriage(int number) {
    struct Carriage *tmp = loco;
    while(tmp ->index != number) {
        tmp = tmp -> next;
    }
    return tmp->taken_place;
}

Train::Take_seats(int carriage_number, int number_of_taken_places) {
    struct Carriage *tmp = loco;
    while (tmp -> index != carriage_number) {
        tmp = tmp -> next;
    }
    if (tmp == nullptr) {
        return 1;
    }
    if (tmp->taken_place + number_of_taken_places <= tmp->total_place){
    tmp ->taken_place += number_of_taken_places;
    return 0;
    }
    else{
        std::cout << "Not enough space!" << std::endl;
        return 1;
    }
}

Train::Add_carriage_to_train(){
    struct Carriage* tmp = loco;
    while (tmp->next != nullptr) {
        tmp = tmp -> next;
    }
    //std::cout << tmp -> index << std::endl;
    tmp -> next = create_new_vagon(tmp->index+1);
};

Train::Get_passenger_number(){
    int sum = 0;
    struct Carriage* tmp = loco;
    sum =+ loco->taken_place;
    while(tmp -> next != nullptr) {
        tmp = tmp -> next;
        sum += tmp->taken_place;
    }
    std::cout << sum << std::endl;
};

Train::Remove_carriage(int quantity, int* t){

    int i=0;
    while (quantity) {
        struct Carriage* tmp = loco;
        i=0
        while(tmp != nullptr) {
            if (tmp -> next -> index == t[i]) {
                free()
            }
        }
    }
    return 1;

}



Train::~Train(){};



