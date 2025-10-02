#include <bits/stdc++.h>
using namespace std;
class Animal{
public: 
    void eat(){
        cout<<"Animal is eating..."<<endl;
    }
    void sleep(){
        cout<<"Animal is sleeping..."<<endl;
    }
};

class Dog : public Animal{
public:
    void bark(){
        cout<<"Dog is barking..."<<endl;
    }
};
int main()
{
    Dog myDog;

    // Inherited methods from animal
    myDog.eat();
    myDog.sleep();

    // Child class specific method
    myDog.bark();
    return 0;
}