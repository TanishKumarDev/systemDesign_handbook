#include <bits/stdc++.h>
using namespace std;
class Circle {
public:
    void draw() { cout << "Drawing Circle" << endl; }
};

class Square {
public:
    void draw() { cout << "Drawing Square" << endl; }
};

int main()
{
    string shapeType;
    // cout << "Enter shape (Circle/Square): ";
    cin >> shapeType;
    if (shapeType == "Circle") {
        Circle c;
        c.draw();
    } else if (shapeType == "Square") {
        Square s;
        s.draw();
    } else {
        cout << "Unknown shape!" << endl;
    }    
    return 0;
}

// 🎯 Factory Pattern
// The Factory family has 3 levels:

// Simple Factory (not part of GoF officially, but widely used)
// Factory Method (GoF Creational Pattern)
// Abstract Factory (GoF Creational Pattern, advanced)
    
// 1️⃣ Simple Factory
// 🚨 Problem

// Suppose we want to build a Shape Drawing App (circle, rectangle, square).
// If we use if-else everywhere → code becomes messy and hard to extend.

// ⚠️ Problem: Adding a new shape → modify main (breaks OCP).