// Lab_03_4.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 5

#include <iostream>
using namespace std;

int main()
{
    double x;  // вхідний аргумент
    double y;  // вхідний аргумент
    double R;  // вхідний параметр (радіус)

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "R = "; cin >> R;

    // розгалуження в повній формі
    if (( x*x + y*y <= R*R && x >= 0 && y >= 0 ) ||
        ( x*x + y*y <= R*R && x <= 0 && y >= 0 && y <= x + R ) ||
        ( x*x + y*y <= R*R && x <= 0 && y <= 0 ))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cin.get();
    return 0;
}