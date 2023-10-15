//Triangles.cpp

#include "Triangles.h"

void Triangles::Init(double s1, double s2, double s3, double a1, double a2, double a3)
{
    sideA = s1;
    sideB = s2;
    sideC = s3;
    angleA = a1;
    angleB = a2;
    angleC = a3;
}

void Triangles::Read()
{
    cout << "Введіть довжини сторін трикутника: ";
    cin >> sideA >> sideB >> sideC;
    cout << "Введіть величини кутів трикутника: ";
    cin >> angleA >> angleB >> angleC;
}

void Triangles::Display()
{
    cout << "Сторони трикутника: " << sideA << ", " << sideB << ", " << sideC << endl;
    cout << "Кути трикутника: " << angleA << ", " << angleB << ", " << angleC << endl;
}

string Triangles::toString()
{
    return "Трикутник: (" + to_string(sideA) + ", " + to_string(sideB) + ", " + to_string(sideC) +
        "), (" + to_string(angleA) + ", " + to_string(angleB) + ", " + to_string(angleC) + ")";
}

double Triangles::CalculateArea()
{
    double s = CalculatePerimeter() / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangles::CalculatePerimeter()
{
    return sideA + sideB + sideC;
}

double Triangles::CalculateIncircleRadius()
{
    double s = CalculatePerimeter() / 2;
    return sqrt(((s - sideA) * (s - sideB) * (s - sideC)) / s);
}

double Triangles::CalculateCircumcircleRadius()
{
    return (sideA * sideB * sideC) / (4 * CalculateArea());
}

double Triangles::CalculateHeight(int sideIndex)
{
    if (sideIndex == 1) {
        return 2 * CalculateArea() / sideA;
    }
    else if (sideIndex == 2) {
        return 2 * CalculateArea() / sideB;
    }
    else if (sideIndex == 3) {
        return 2 * CalculateArea() / sideC;
    }
    else {
        return -1.0; // Помилка - невірний індекс
    }
}

string Triangles::DetermineType()
{
    if (angleA == 90.0 || angleB == 90.0 || angleC == 90.0) {
        return "Прямокутний трикутник";
    }
    else if (angleA == angleB && angleB == angleC) {
        return "Рівносторонній трикутник";
    }
    else if (sideA == sideB || sideB == sideC || sideA == sideC) {
        return "Рівнобедрений трикутник";
    }
    else {
        return "Звичайний трикутник";
    }
}

bool Triangles::operator==(const Triangles& other) const
{
    return (sideA == other.sideA && sideB == other.sideB && sideC == other.sideC &&
        angleA == other.angleA && angleB == other.angleB && angleC == other.angleC);
}

bool Triangles::operator!=(const Triangles& other) const
{
    return !(*this == other);
}

void Triangles::CalculateAngles()
{
    // Обчислюємо кути трикутника зі сторін
    angleA = acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC)) * 180 / M_PI;
    angleB = acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2 * sideA * sideC)) * 180 / M_PI;
    angleC = 180 - angleA - angleB;
}

istream& operator>>(istream& is, Triangles& triangle)
{
    cout << "Введіть довжини сторін трикутника: ";
    is >> triangle.sideA >> triangle.sideB >> triangle.sideC;
    cout << "Введіть величини кутів трикутника: ";
    is >> triangle.angleA >> triangle.angleB >> triangle.angleC;
    return is;
}
