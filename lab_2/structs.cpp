#include "structs.h"
#define PI 3.14159265


lab2::Descartes_list::Descartes_list() : n(0), angle(0) {};

lab2::Descartes_list::Descartes_list(double a) {
    n = a;
}

lab2::Descartes_list::Descartes_list(double a, double ang) {
    n = a;
    angle = ang;
}

void lab2::Descartes_list::change_n(double a) {
    input::getNum(a, "Enter new value of n: ");
    n = a;
}

double lab2::Descartes_list::return_square_size() {
    double square_site;
    square_site = n / (sqrt(2));
    return square_site; 
}

double lab2::Descartes_list::center_distance() {
    double distance;
    angle = angle * PI / 180.0;
    double l = return_square_size();
    double si = sin(angle);
    double co = cos(angle);
    distance = l * (pow(si,2) - pow(co,2)) / (3 * pow(si,3) + pow(co,3));
    return distance;

}

double lab2::Descartes_list::vertex_radius_of_curvature() {
    double r;
    r = (n)/(8 * sqrt(2));
    return r;
}

double lab2::Descartes_list::knot_radius_of_curvature() {
    double r_k;
    r_k = (n)/(2);
    return r_k;
}

double lab2::Descartes_list::loop_area() {
    double s;
    s = pow((return_square_size()/3),2);
    return s;
}

double lab2::Descartes_list::diameter_value() {
    double l = return_square_size();
    double diameter;
    diameter = 2 * l/3 * sqrt(2 * sqrt(3) - 3);
    return diameter;
}

double lab2::Descartes_list::diameter_distance() {
    double l = return_square_size();
    double distance = l/3 * sqrt(3);
    return distance;
}


