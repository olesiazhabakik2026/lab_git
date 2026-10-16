#include <iostream>
#include <cmath>
 
using namespace std;
 
// i-й множник добутку
double f(const int i)
{
    return (pow(sin(1. * i), 2) + pow(cos(1. / i), 2)) / (1. * i * i);
}
 
// ітераційний спосіб
double P0(const int K, const int N)
{
    double p = 1;
    for (int i = K; i <= N; i++)
        p *= f(i);
    return p;
}
 
// рекурсія вгору, значення формується при поверненні (i = K, K+1, ..., N)
double P1(const int K, const int N, const int i)
{
    if (i > N)
        return 1;
    else
        return f(i) * P1(K, N, i + 1);
}
 
// рекурсія вниз, значення формується при поверненні (i = N, N-1, ..., K)
double P2(const int K, const int N, const int i)
{
    if (i < K)
        return 1;
    else
        return f(i) * P2(K, N, i - 1);
}
 
// рекурсія вгору, добуток накопичується в параметрі t (початкове t = 1)
double P3(const int K, const int N, const int i, double t)
{
    t = t * f(i);
    if (i >= N)
        return t;
    else
        return P3(K, N, i + 1, t);
}
 
// рекурсія вниз, добуток накопичується в параметрі t (початкове t = 1)
double P4(const int K, const int N, const int i, double t)
{
    t = t * f(i);
    if (i <= K)
        return t;
    else
        return P4(K, N, i - 1, t);
}
 
int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;
 
    cout << "(iter)          P0 = " << P0(K, N)       << endl;
    cout << "(rec up ++)     P1 = " << P1(K, N, K)    << endl;
    cout << "(rec up --)     P2 = " << P2(K, N, N)    << endl;
    cout << "(rec down ++)   P3 = " << P3(K, N, K, 1) << endl;
    cout << "(rec down --)   P4 = " << P4(K, N, N, 1) << endl;
 
    return 0;
}