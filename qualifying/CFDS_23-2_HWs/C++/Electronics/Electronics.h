#pragma once

// Fill in here
class Electronics{
protected: 
    float size, w;
    int GPU;
public:
    Electronics();
    float GetSize();
    float GetW();
    virtual void PrintSelf() = 0;
    virtual float GetPrice() = 0;
    virtual ~Electronics();
};

class TV: public Electronics{
public:
    TV(float _size);
    virtual float GetPrice();
    virtual void PrintSelf();
};

class Computer: public Electronics{
public:
    Computer(float _size);
    virtual float GetPrice();
    virtual void PrintSelf();
};

class Cellphone: public Electronics{
public:
    Cellphone(float _size);
    virtual float GetPrice();
    virtual void PrintSelf();
};

class Laptop: public Computer{
public:
    Laptop(float _size);
    void AddGPU(Electronics *aGPU);
    virtual float GetPrice();
};

class Desktop: public Computer{
private:
    float GPU_price;
public:
    Desktop(float _size);
    void AddGPU(Electronics *aGPU);
    virtual float GetPrice();
    virtual void PrintSelf();
};






