#include "mycode.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

// Fill in
using namespace std;

float Shape ::area(float a) { 
    side = a;
    return side; 
}

void Shape ::print() {
    cout << fixed;
    cout.precision(6);
    cout << "This is Shape. Area is " << double(output) << endl;
}

float Square ::area(float a) { return side * side; }
void Square ::print() {
    cout << fixed;
    cout.precision(6);
    cout << "This is Square. Area is " << double(output) << endl;
}

float Equilateral::area(float a) { return sqrt(3) / 4 * side * side; }
void Equilateral::print() {
    cout << fixed;
    cout.precision(6);
    cout << "This is Equilateral. Area is " << double(output) << endl;
}
