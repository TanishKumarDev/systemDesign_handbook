#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public: 
    // pure virtual function
    virtual void accelerate() = 0;
    virtual void brake() = 0;

    // Concrete method
    void startEngine() {
        cout << "Engine started"<<endl;
    }
    void honk() {
        cout << "Beep! Beep!"<<endl;
    }
};

// Concrete Class
class Car : public Vehicle {
public:

    void accelerate() override{
        std::cout << "Car: Pressing gas pedal..." << std::endl;
    }

    void brake() override {
        std::cout << "Car: Applying brakes..." << std::endl;
    }
};

int main()
{
    Vehicle* myCar = new Car(); 
    myCar->startEngine();
    myCar->accelerate();
    myCar->brake();
    delete myCar;
    return 0;
}