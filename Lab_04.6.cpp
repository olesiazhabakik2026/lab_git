#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double P, S;
    int n, k;

    // 1. Цикл while
    P = 1;
    n = 1;
    while (n<=10)
    {
        S = 0;
        k = 1;
        while (k<=n)
        {
            S += 1./k;
            k++;
        }
        P *= (n+S)/sqrt(S);
        n++;
    }
    cout << P << endl;

    // 2. Цикл do-while
    P = 1;
    n = 1;
    do {
        S = 0;
        k = 1;
        do {
            S += 1./k;
            k++;
        } while (k<=n);
        P *= (n+S)/sqrt(S);
        n++;
    } while (n<=10);
    cout << P << endl;

    // 3. Цикл for (за зростанням)
    P = 1;
    for (n=1; n<=10; n++)
    {
        S = 0;
        for (k=1; k<=n; k++)
        {
            S += 1./k;
        }
        P *= (n+S)/sqrt(S);
    }
    cout << P << endl;

    // 4. Цикл for (за спаданням)
    P = 1;
    for (n=10; n>=1; n--)
    {
        S = 0;
        for (k=n; k>=1; k--)
        {
            S += 1./k;
        }
        P *= (n+S)/sqrt(S);
    }
    cout << P << endl;

    return 0;
}