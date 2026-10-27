#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Заповнення масиву випадковими числами з діапазону [MIN; MAX]
void create(int arr[], int SIZE, int MIN, int MAX) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % (MAX - MIN + 1) + MIN;
    }
}

// Виведення масиву
void print(int arr[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Середнє арифметичне непарних елементів
// Якщо непарних елементів немає, повертає 0
double FindingTheArithmetic(int arr[], int SIZE) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }
    return (double)sum / count;
}

int main() {
    const int SIZE = 10;
    const int MIN = -20;
    const int MAX = 30;

    int arr[SIZE];

    srand(time(0));

    create(arr, SIZE, MIN, MAX);

    cout << "Масив arr:" << endl;
    print(arr, SIZE);

    double result = FindingTheArithmetic(arr, SIZE);

    if (result == 0) {
        cout << "Непарних елементів немає." << endl;
    } else {
        cout << "Середнє арифметичне непарних елементів: " << result << endl;
    }

    return 0;
}