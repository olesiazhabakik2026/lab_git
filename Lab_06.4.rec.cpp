#include <iostream>
#include <cmath>
using namespace std;

void create(double* arr, int n, int i);
void print(double* arr, int n, int i);
double MaxElement(double* arr, int n, int i);
int LastPositiveIndex(double* arr, int i);
double SumBeforeLastPositive(double* arr, int last, int i);
void FillZeros(double* arr, int n, int k);
void Compress(double* arr, int n, double a, double b, int i, int j);

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
        swap(a, b);                     // щоб інтервал [a, b] був коректним

    double* arr = new double[n];

    create(arr, n, 0);
    cout << "Масив:" << endl;
    print(arr, n, 0);

    // 1.1 Максимальний елемент
    cout << "Максимальний елемент: " << MaxElement(arr, n, 0) << endl;

    // 1.2 Сума елементів до останнього додатного
    int last = LastPositiveIndex(arr, n - 1);
    if (last == -1)
        cout << "Додатних елементів немає, суму знайти неможливо." << endl;
    else
        cout << "Сума елементів до останнього додатного: "
             << SumBeforeLastPositive(arr, last, 0) << endl;

    // 2. Стиснення масиву
    Compress(arr, n, a, b, 0, 0);
    cout << "Масив після стиснення:" << endl;
    print(arr, n, 0);

    delete[] arr;
    return 0;
}

// Введення елементів з клавіатури
void create(double* arr, int n, int i)
{
    if (i < n)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
        create(arr, n, i + 1);
    }
}

// Виведення масиву
void print(double* arr, int n, int i)
{
    if (i < n)
    {
        cout << arr[i] << " ";
        print(arr, n, i + 1);
    }
    else
        cout << endl;
}

// 1.1 Максимум із arr[i] та максимуму решти масиву
double MaxElement(double* arr, int n, int i)
{
    if (i == n - 1)
        return arr[i];
    double m = MaxElement(arr, n, i + 1);
    return arr[i] > m ? arr[i] : m;
}

// Індекс останнього додатного елемента: шукаємо з кінця (i починається з n - 1)
int LastPositiveIndex(double* arr, int i)
{
    if (i < 0)
        return -1;
    if (arr[i] > 0)
        return i;
    return LastPositiveIndex(arr, i - 1);
}

// 1.2 Сума елементів з індексами від i до last (не включно)
double SumBeforeLastPositive(double* arr, int last, int i)
{
    if (i < last)
        return arr[i] + SumBeforeLastPositive(arr, last, i + 1);
    return 0;
}

// Заповнення нулями елементів від k до кінця
void FillZeros(double* arr, int n, int k)
{
    if (k < n)
    {
        arr[k] = 0;
        FillZeros(arr, n, k + 1);
    }
}

// 2. Стиснення: i читає елементи, j показує, куди записувати наступний
void Compress(double* arr, int n, double a, double b, int i, int j)
{
    if (i < n)
    {
        double m = fabs(arr[i]);
        if (!(m >= a && m <= b))
        {
            arr[j] = arr[i];
            Compress(arr, n, a, b, i + 1, j + 1);
        }
        else
            Compress(arr, n, a, b, i + 1, j);
    }
    else
        FillZeros(arr, n, j);           // базовий випадок: решту заповнюємо нулями
}