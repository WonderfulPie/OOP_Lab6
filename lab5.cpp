//Lab5.cpp

#include <iostream>
#include <cmath>
#include <Windows.h>
#include "../Lab5/Triangles.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangles triangle; // ��������������� ����������� �� �������������
    triangle.Read();
    triangle.Display();
    cout << "����� ����������: " << triangle.CalculateArea() << endl;
    cout << "�������� ����������: " << triangle.CalculatePerimeter() << endl;
    cout << "����� ��������� ���� " << triangle.CalculateIncircleRadius() << endl;
    cout << "����� ��������� ����: " << triangle.CalculateCircumcircleRadius() << endl;
    cout << "��� ����������: " << triangle.DetermineType() << endl;

    return 0;
}