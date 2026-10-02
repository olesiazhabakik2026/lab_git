#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k, N, i;
    double P;

    k = 1;
    N = 15;

    // цикл while
    P = 1;
    i = k;
    while (i <= N)
    {
        P *= (pow(sin(1.*i), 2) + pow(cos(1./i), 2)) / (i*i);
        i++;
    }
    cout << P << endl;

    // цикл do-while
    P = 1;
    i = k;
    do {
        P *= (pow(sin(1.*i), 2) + pow(cos(1./i), 2)) / (i*i);
        i++;
    } while (i <= N);
    cout << P << endl;

    // цикл for (за зростанням i)
    P = 1;
    for (i = k; i <= N; i++)
    {
        P *= (pow(sin(1.*i), 2) + pow(cos(1./i), 2)) / (i*i);
    }
    cout << P << endl;

    // цикл for (за спаданням i)
    P = 1;
    for (i = N; i >= k; i--)
    {
        P *= (pow(sin(1.*i), 2) + pow(cos(1./i), 2)) / (i*i);
    }
    cout << P << endl;

    return 0;
}