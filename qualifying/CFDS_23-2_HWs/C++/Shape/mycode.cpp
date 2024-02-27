#include "mycode.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

// Fill in

Shape::Shape(){};
Shape::Shape(float _side){side = _side;}
void Shape::print(){
    cout << "This is Shape. Area is " << area() << endl;
}
Shape::~Shape(){};


Square::Square(float _side): Shape(_side){}
float Square::area(){
    return side*side;
}
void Square::print(){
    cout << "This is Square. Area is " << area() << endl;
}

Equilateral::Equilateral(float _side): Shape(_side){}
float Equilateral::area(){
    return sqrt(3)*0.25*side*side;
}
void Equilateral::print(){
    cout << "This is Equilateral. Area is " << area() << endl;
}
