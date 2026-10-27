#include <iostream>
#include <cmath>
using namespace std;

void create(double* arr, int n);
void print(double* arr, int n);
double MaxElement(double* arr, int n);
int LastPositiveIndex(double* arr, int n);
double SumBeforeLastPositive(double* arr, int n, int last);
void Compress(double* arr, int n, double a, double b);

int main()
{
    int n;
    double a, b;

    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n має бути додатним." << endl;
        return 0;
    }

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    if (a > b)
        swap(a, b);                 // щоб інтервал [a, b] був коректним

    double* arr = new double[n];

    create(arr, n);
    cout << "Масив:" << endl;
    print(arr, n);

    // 1.1
    cout << "Максимальний елемент: " << MaxElement(arr, n) << endl;

    // 1.2
    int last = LastPositiveIndex(arr, n);
    if (last == -1)
        cout << "Додатних елементів немає, суму знайти неможливо." << endl;
    else
        cout << "Сума елементів до останнього додатного: "
             << SumBeforeLastPositive(arr, n, last) << endl;

    // 2
    Compress(arr, n, a, b);
    cout << "Масив після стиснення:" << endl;
    print(arr, n);

    delete[] arr;
    return 0;
}

// Введення елементів з клавіатури
void create(double* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

// Виведення масиву
void print(double* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 1.1 Максимальний елемент
double MaxElement(double* arr, int n)
{
    double max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Індекс останнього додатного елемента (-1, якщо його немає)
int LastPositiveIndex(double* arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] > 0)
            return i;
    return -1;
}

// 1.2 Сума елементів, розташованих до останнього додатного
double SumBeforeLastPositive(double* arr, int n, int last)
{
    double sum = 0;
    for (int i = 0; i < last; i++)
        sum += arr[i];
    return sum;
}

// 2. Стиснення масиву: видаляємо елементи, модуль яких у [a, b],
// решту зсуваємо вліво, звільнені місця в кінці заповнюємо нулями
void Compress(double* arr, int n, double a, double b)
{
    int j = 0;                                  // куди записувати наступний елемент
    for (int i = 0; i < n; i++)
    {
        double m = fabs(arr[i]);
        if (!(m >= a && m <= b))
        {
            arr[j] = arr[i];
            j++;
        }
    }
    for (int k = j; k < n; k++)
        arr[k] = 0;
}