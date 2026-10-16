// Лабораторна робота № 5.5, варіант 5
// Q(m, n) - кількість розбиттів цілого числа m на доданки, що не перевищують n.
// Окрім значення функції, визначаємо глибину рекурсії.

#include <iostream>

using namespace std;

// depth    - номер поточного рівня рекурсії (перший виклик має depth = 1)
// maxDepth - найбільша глибина, досягнута за весь час обчислення
int Q(const int m, const int n, const int depth, int &maxDepth)
{
    if (depth > maxDepth)
        maxDepth = depth;

    if (n == 1)                         // Q(m, 1) = 1
        return 1;
    if (m == 1)                         // Q(1, n) = 1
        return 1;
    if (m < n)                          // Q(m, n) = Q(m, m), якщо m < n
        return Q(m, m, depth + 1, maxDepth);
    if (m == n)                         // Q(m, m) = 1 + Q(m, m-1)
        return 1 + Q(m, m - 1, depth + 1, maxDepth);

    // m > n:  Q(m, n) = Q(m, n-1) + Q(m-n, n)
    return Q(m, n - 1, depth + 1, maxDepth)
         + Q(m - n, n, depth + 1, maxDepth);
}

int main()
{
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;

    if (m <= 0 || n <= 0)
    {
        cout << "m і n мають бути додатними цілими" << endl;
        return 1;
    }

    int maxDepth = 0;
    int result = Q(m, n, 1, maxDepth);

    cout << "Q(" << m << ", " << n << ") = " << result << endl;
    cout << "Глибина рекурсії = " << maxDepth << endl;

    return 0;
}