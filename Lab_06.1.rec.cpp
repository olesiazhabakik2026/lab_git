#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Заповнення масиву випадковими числами з діапазону [MIN; MAX]
void create(int arr[], int SIZE, int MIN, int MAX, int i) {
    if (i >= SIZE) {
        return;                                   // базовий випадок
    }
    arr[i] = rand() % (MAX - MIN + 1) + MIN;
    create(arr, SIZE, MIN, MAX, i + 1);           // рекурсивний крок
}

// Виведення масиву
void print(int arr[], int SIZE, int i) {
    if (i >= SIZE) {
        cout << endl;
        return;
    }
    cout << arr[i] << " ";
    print(arr, SIZE, i + 1);
}

// Пошук додатних парних елементів, їх суми та кількості
void FindingTheArithmetic(int arr[], int SIZE, int i, int &sum, int &count) {
    if (i >= SIZE) {
        return;
    }
    if (arr[i] > 0 && arr[i] % 2 == 0) {
        cout << "a[" << i << "] = " << arr[i] << endl;
        sum += arr[i];
        count++;
    }
    FindingTheArithmetic(arr, SIZE, i + 1, sum, count);
}

int main() {
    const int SIZE = 25;
    const int MIN = -20;
    const int MAX = 30;

    int arr[SIZE];
    int sum = 0;
    int count = 0;

    srand(time(0));

    create(arr, SIZE, MIN, MAX, 0);

    cout << "Масив arr:" << endl;
    print(arr, SIZE, 0);

    cout << "Додатні парні елементи:" << endl;
    FindingTheArithmetic(arr, SIZE, 0, sum, count);

    if (count == 0) {
        cout << "Таких елементів немає." << endl;
    } else {
        cout << "Кількість: " << count << endl;
        cout << "Сума: " << sum << endl;
        cout << "Середнє арифметичне: " << (double)sum / count << endl;
    }

    return 0;
}