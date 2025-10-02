#include <bits/stdc++.h>
using namespace std;

// 1️⃣ Compile-Time Polymorphism (Function Overloading)
class Math {
    public:
    // same function name, different parameters
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
    double add(double a, double b, double c) {
        return a + b + c;
    }
};

// 2️⃣ Run-Time Polymorphism (Virtual Functions)
class Animal {
    public: 
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
    public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
    public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};
int main()
{
    
    // 1️⃣ Compile-Time Polymorphism (Function Overloading)
    
    Math mathObj;
    cout << mathObj.add(10, 20) << endl;
    cout << mathObj.add(10.5, 20.5) << endl;
    cout << mathObj.add(10, 20, 30) << endl;
    cout << mathObj.add(10.5, 20.5, 30.5) << endl;

    // 2️⃣ Run-Time Polymorphism (Virtual Functions)
    Animal* animalObj1 = new Dog();
    Animal* animalObj2 = new Dog();

    animalObj1->sound();
    animalObj2->sound();

    delete animalObj1;
    delete animalObj2;
    
    return 0;
}