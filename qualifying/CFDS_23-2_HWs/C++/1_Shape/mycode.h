#pragma once

// Fill in
class Shape {
  public:
    float side;
    float output;
    Shape(float a) { output = area(a); }
    virtual float area(float a);
    void print();
};

class Square : public Shape {
  public:
    Square(float a) : Shape(a) { output = area(a); }
    float area(float a);
    void print();
};

class Equilateral : public Shape {
  public:
    Equilateral(float a) : Shape(a) { output = area(a); }
    float area(float a);
    void print();
};