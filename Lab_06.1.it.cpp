#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 25;
    int a[N];

    srand(time(0));

    // Заповнення масиву випадковими числами з діапазону [-20; 30]
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 51 - 20;
    }

    // Виведення масиву
    cout << "Масив a:" << endl;
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Пошук елементів за критерієм: додатні та парні
    int count = 0;
    int sum = 0;

    cout << "Додатні парні елементи:" << endl;
    for (int i = 0; i < N; i++) {
        if (a[i] > 0 && a[i] % 2 == 0) {
            cout << "a[" << i << "] = " << a[i] << endl;
            count++;
            sum += a[i];
        }
    }

    if (count == 0) {
        cout << "Таких елементів немає." << endl;
    } else {
        cout << "Кількість: " << count << endl;
        cout << "Сума: " << sum << endl;
    }

    return 0;
}