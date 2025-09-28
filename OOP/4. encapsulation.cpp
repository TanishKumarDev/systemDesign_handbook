#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    int id;
    string name;

public:

    // Setter Methods
    void setId(int id){
        this->id = id;
    }

    void setName(string name){
        this->name = name;
    }

    // Getter Methods
    int getId(){
        return id;
    }

    string getName(){
        return name;
    }
};

int main()
{  
    Employee emp;

    // Using setters
    emp.setId(101);
    emp.setName("Geek");

    // Using getters
    cout << "Id: " << emp.getId() << endl;
    cout << "Name: " << emp.getName() << endl;
    
    return 0;
}