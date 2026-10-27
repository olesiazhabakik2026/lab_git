#include <iostream>
#include <string>
using namespace std;

void Pass(int* a, const int size, int j);
void Sort(int* a, const int size, int i);

template <typename T>
void Pass(T* a, const int size, int j);

template <typename T>
void Sort(T* a, const int size, int i);

template <typename T>
void Print(T* a, const int size, int i);

int main()
{
    const int n = 10;

    int a[n] = { 5, 2, 9, 1, 7, 3, 8, 3, 10, 6 };
    cout << "Було (int):            ";
    Print(a, n, 0);
    Sort(a, n, 0);
    cout << "Sort(a, n, 0):         ";
    Print(a, n, 0);

    int a2[n] = { 4, 8, 1, 9, 2, 7, 5, 6, 3, 10 };
    Sort<int>(a2, n, 0);
    cout << "Sort<int>(a2, n, 0):   ";
    Print(a2, n, 0);

    double b[n] = { 1.1, 9.9, 3.3, 4.3, 10.0, 6.6, 7.7, 2.2, 5.5, 8.8 };
    cout << "Було (double):         ";
    Print(b, n, 0);
    Sort<double>(b, n, 0);
    cout << "Sort<double>(b, n, 0): ";
    Print(b, n, 0);

    string c[n] = { "kiwi", "apple", "pear", "plum", "fig",
                    "grape", "lemon", "mango", "cherry", "banana" };
    cout << "Було (string):         ";
    Print(c, n, 0);
    Sort<string>(c, n, 0);
    cout << "Sort<string>(c, n, 0): ";
    Print(c, n, 0);

    return 0;
}

// Один прохід по перших size елементах: менший елемент рухається вправо
void Pass(int* a, const int size, int j)
{
    if (j < size - 1)
    {
        if (a[j] < a[j + 1])
        {
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
        Pass(a, size, j + 1);
    }
}

// Сортування за не зростанням; i рахує кількість виконаних проходів
void Sort(int* a, const int size, int i)
{
    if (i < size - 1)
    {
        Pass(a, size - i, 0);
        Sort(a, size, i + 1);
    }
}

template <typename T>
void Pass(T* a, const int size, int j)
{
    if (j < size - 1)
    {
        if (a[j] < a[j + 1])
        {
            T tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
        Pass<T>(a, size, j + 1);
    }
}

template <typename T>
void Sort(T* a, const int size, int i)
{
    if (i < size - 1)
    {
        Pass<T>(a, size - i, 0);
        Sort<T>(a, size, i + 1);
    }
}

template <typename T>
void Print(T* a, const int size, int i)
{
    if (i < size)
    {
        cout << a[i] << " ";
        Print<T>(a, size, i + 1);
    }
    else
        cout << endl;
}