#include "Electronics.h"
#include <iostream>
using namespace std;

// Fill in here
Electronics::Electronics(){}
float Electronics::GetSize(){return size;}
float Electronics::GetW(){return w;}
Electronics::~Electronics(){}

TV::TV(float _size){
    size = _size;
    w = 1.8;
}
float TV::GetPrice(){return size*w;}
void TV::PrintSelf(){cout << "It is a TV, Size=" << size << ", Price=" << GetPrice() << endl;}

Computer::Computer(float _size){
    size = _size;
    w = 0.6;
}
float Computer::GetPrice(){return size*w;}
void Computer::PrintSelf(){cout << "It is a Computer, Size=" << size << ", Price=" << GetPrice() << endl;}

Cellphone::Cellphone(float _size){
    size = _size;
    w = 0.7;
}
float Cellphone::GetPrice(){return size*w;}
void Cellphone::PrintSelf(){cout << "It is a Cellphone, Size=" << size << ", Price=" << GetPrice() << endl;}

Laptop::Laptop(float _size):Computer(_size){}
void Laptop::AddGPU(Electronics *aGPU){
    if (GPU < 1){
        GPU++;
    }
}
float Laptop::GetPrice(){
    if (GPU>0){
        return size*w*2; 
    }else{
        return size*w;
    }
}


Desktop::Desktop(float _size):Computer(_size){}
void Desktop::AddGPU(Electronics *aGPU){
    if (GPU < 2){
        GPU++;
        GPU_price += aGPU->GetSize() * aGPU->GetW();
    }
}
float Desktop::GetPrice(){
    if (GPU>0){
        return size*w*1.8; 
    }else{
        return size*w;
    }
}
void Desktop::PrintSelf(){

    cout << "It is a Desktop with " << GPU << " GPU(s), Size=" << size << ", Price=" << GetPrice() << ", Total Price=" << GetPrice()+GPU_price << endl;
}

