#pragma once

// Fill in
class Shape{
protected:
    float side;

public:
    Shape();
    Shape(float _side);
    virtual float area() = 0;
    void print();
    virtual ~Shape();
};

class Square: public Shape{
public:
    Square(float _side);
    virtual float area();
    void print();
};

class Equilateral: public Shape{
public:
    Equilateral(float _side);
    virtual float area();
    void print();
};