//Lab5.cpp

#include <iostream>
#include <cmath>
#include <Windows.h>
#include "../Lab5/Triangles.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangles triangle; // Використовується конструктор за замовчуванням
    triangle.Read();
    triangle.Display();
    cout << "Площа трикутника: " << triangle.CalculateArea() << endl;
    cout << "Периметр трикутника: " << triangle.CalculatePerimeter() << endl;
    cout << "Радіус вписаного кола " << triangle.CalculateIncircleRadius() << endl;
    cout << "Рудіус описаного кола: " << triangle.CalculateCircumcircleRadius() << endl;
    cout << "Тип трикутника: " << triangle.DetermineType() << endl;

    return 0;
}