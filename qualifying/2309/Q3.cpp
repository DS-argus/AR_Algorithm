#include <iostream>
#include <string>
#include <cmath>
// #include <algorithm>

using namespace std;

class Shape{
public:

    //이걸 없애도 Rectangle(w, h), Triangle(a, b, c)를 호출하는데 문제없음 -> why?
    //기본적으로 자식 class가 호출되면 그 전에 부모 class의 생성자 호출. 생성자 오버라이딩이 없다면 알아서 기본 생성자 호출.
    //Shape class의 경우 기본 생성자가 있기 때문에 문제 없이 실행되고, 주석처리해도 알아서 기본 생성자 호출함
    Shape(){
        // cout << "Shape constructor called" << endl;
    };

    //virtual로 하는게 맞아보이지만, 문제에서 별말 없음
    string get_name(void){
        return "Shape";
    };

    //pure virtual은 = 0 해줘야 함. 그냥 virtual은 필요없고 함수 body 채워도 됨.
    // = NULL은 안됨 why?
    virtual double calc_area(void) = 0;

    // pure virtual function이 있는 abstract class는 소멸자도 virtual로 해줘야 함.
    // virtual 소멸자는 함수 body {} 가 있어야 함.
    virtual ~Shape(){};

};


class Rectangle:  public Shape{
private:
    double w, h;

public:

    //이걸 없애면 Square(w)를 호출할 때 문제발생 -> why?
    //Rectangle(double height, double width)로 overriding했기 때문에 기본생성자 호출안돼서 오류 발생
    Rectangle(){
        // cout << "Rectangle constructor called" << endl;
    };

    Rectangle(double height, double width){
        // cout << "Rectangle(double height, double width) constructor called" << endl;
        w = width;
        h = height;
    }

    virtual double calc_area(){
        return w*h;        
    }

    string get_name(){
        return "Rectangle";
    }

    ~Rectangle(){};

};

class Square: public Rectangle{
public: 

    // Square(){
    //     // cout << "Square constructor called" << endl;
    // }

    Square(double width): Rectangle(width, width){
        // cout << "Shape(double width) constructor called" << endl;
    }

    string get_name(){
        return "Square";
    }

    ~Square(){};

};

class Triangle: public Shape{
private:
    double a, b, c;

public:

    //이걸 없애면 Righttriangle(a, b)를 호출할 때 문제발생 -> why?
    // 위와 같은 이유
    Triangle(){
        // cout << "Triangle constructor called" << endl;
    };

    Triangle(double _a, double _b, double _c){
        // cout << "Triangle(double _a, double _b, double _c) constructor called" << endl;
        a = _a;
        b = _b;
        c = _c;
    }

    virtual double calc_area(){
        int max_len = max(max(a, b), c);
        
        if (max_len == a){
            if (a >= b+c) return -1;
        }else if(max_len == b){
            if (b >= a+c) return -1;
        }else{
            if (c >= a+b) return -1;
        }

        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c)); 
    }


    string get_name(){
        return "Triangle";
    }

    ~Triangle(){};

};

class RightTriangle: public Triangle{
public:

    // RightTriangle(){
    //     // cout << "RightTriangle constructor called" << endl;
    // }

    RightTriangle(double _a, double _b): Triangle(_a, _b,sqrt(_a*_a+_b*_b)){
        // cout << "RightTriangle(double _a, double _b) constructor called" << endl;
    }
    
    string get_name(){
        return "Right Triangle";
    }

    ~RightTriangle(){};
};


int main(void) {

    // abstact class
    // Shape* a = new Shape;
    Shape* a = new Rectangle(3.0,4.0);
    cout << a -> calc_area() << endl;
    cout << a -> get_name() << endl;

    Shape* b = new Square(3.5);
    cout << b -> calc_area() << endl;
    cout << b -> get_name() << endl;

    Shape* c = new Triangle(3.5, 2.0, 4.5);
    cout << c -> calc_area() << endl;
    cout << c -> get_name() << endl;

    Shape* d = new RightTriangle(3.5, 2.0);
    cout << d -> calc_area() << endl;
    cout << d -> get_name() << endl;

    delete(a);
    delete(b);
    delete(c);
    delete(d);

    return 0;
}



