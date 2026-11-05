#include <iostream>
#include <string>
using namespace std;

void Sort(int* a, const int size);

template <typename T>
void Sort(T* a, const int size);

template <typename T>
void Print(T* a, const int size);

int main()
{
    const int n = 10;

    int a[n] = { 5, 2, 9, 1, 7, 3, 8, 3, 10, 6 };
    cout << "Було (int):      ";
    Print(a, n);
    Sort(a, n);
    cout << "Sort(a, n):      ";
    Print(a, n);

    int a2[n] = { 4, 8, 1, 9, 2, 7, 5, 6, 3, 10 };
    Sort<int>(a2, n);
    cout << "Sort<int>(a2, n): ";
    Print(a2, n);

    double b[n] = { 1.1, 9.9, 3.3, 4.3, 10.0, 6.6, 7.7, 2.2, 5.5, 8.8 };
    cout << "Було (double):   ";
    Print(b, n);
    Sort<double>(b, n);
    cout << "Sort<double>(b, n): ";
    Print(b, n);

    string c[n] = { "kiwi", "apple", "pear", "plum", "fig",
                    "grape", "lemon", "mango", "cherry", "banana" };
    cout << "Було (string):   ";
    Print(c, n);
    Sort<string>(c, n);
    cout << "Sort<string>(c, n): ";
    Print(c, n);

    return 0;
}

// Звичайна функція для int: сортування за не зростанням (бульбашкою)
void Sort(int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// Шаблонна функція для будь-якого типу, який підтримує оператор <
template <typename T>
void Sort(T* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// Виведення масиву будь-якого типу
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}