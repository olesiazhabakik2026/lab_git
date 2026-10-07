// Лабораторна робота № 5.2, варіант 5
// ln((1+x)/(1-x)) = 2 * сума( x^(2n+1) / (2n+1) ),  |x| < 1
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// ширини комірок таблиці (без пробілів по краях)
const int WX = 7;    // x
const int WL = 15;   // ln((1+x)/(1-x))
const int WS = 11;   // S
const int WN = 5;    // n

// ============================================================
// ПРОТОТИПИ
// ============================================================

// 1-й спосіб: void-функції (результат повертається через параметр-посилання)
void S1(const double x, const double eps, int &n, double &s);
void A1(const double x, const int n, double &a);

// 2-й спосіб: double-функції (результат повертається через return)
double S2(const double x, const double eps, int &n, double s);
double A2(const double x, const int n, double a);

// допоміжні функції для малювання таблиці
int    len(const string& s);
string rep(const string& s, int n);
string center(const string& s, int w);
string right(const string& s, int w);
string num(double v, int prec);
string hline(const string& l, const string& m, const string& r);
void   printTop();
void   printRow(double x, double s, int n);
void   printBottom();

// ============================================================
// ГОЛОВНА ФУНКЦІЯ
// ============================================================
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    // введення даних
    cout << "xp = ";  cin >> xp;
    cout << "xk = ";  cin >> xk;
    cout << "dx = ";  cin >> dx;
    cout << "eps = "; cin >> eps;

    // перевірка: крок додатний, а x лежить в області збіжності |x| < 1
    if (dx <= 0 || xp <= -1 || xk >= 1) {
        cout << "Потрібно: dx > 0 і |x| < 1" << endl;
        return 1;
    }

    // ---------- 1-й СПОСІБ: void-функції ----------
    cout << endl << "1-й спосіб: void-функції" << endl;
    printTop();
    // x рахуємо як xp + i*dx, щоб не накопичувалась похибка
    for (int i = 0; (x = xp + i * dx) <= xk + 1e-9; i++)
    {
        S1(x, eps, n, s);     // s і n змінюються всередині функції
        printRow(x, s, n);
    }
    printBottom();

    // ---------- 2-й СПОСІБ: double-функції ----------
    cout << endl << "2-й спосіб: double-функції" << endl;
    printTop();
    for (int i = 0; (x = xp + i * dx) <= xk + 1e-9; i++)
    {
        s = S2(x, eps, n, s); // суму отримуємо через return, n змінюється через &
        printRow(x, s, n);
    }
    printBottom();

    return 0;
}

// ============================================================
// 1-й СПОСІБ: void-функції
// ============================================================

// Обчислює суму ряду s та кількість доданків n з точністю eps
void S1(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = x;      // перший член ряду: a0 = x
    s = a;             // початкове значення суми
    do {
        n++;
        A1(x, n, a);   // обчислюємо наступний член через попередній
        s += a;
    } while (fabs(a) >= eps);   // зупиняємось, коли член менший за eps
}

// Перераховує член ряду: a_n = a_(n-1) * x^2 * (2n-1)/(2n+1)
void A1(const double x, const int n, double &a)
{
    double R = x * x * (2.0 * n - 1) / (2.0 * n + 1);  // 2.0, щоб ділення було дробовим
    a *= R;
}

// ============================================================
// 2-й СПОСІБ: double-функції
// ============================================================

// Те саме, але суму повертаємо через return
double S2(const double x, const double eps, int &n, double s)
{
    n = 0;
    double a = x;      // перший член ряду
    s = a;
    do {
        n++;
        a = A2(x, n, a);   // наступний член отримуємо через return
        s += a;
    } while (fabs(a) >= eps);
    return s;
}

// Повертає наступний член ряду
double A2(const double x, const int n, double a)
{
    double R = x * x * (2.0 * n - 1) / (2.0 * n + 1);
    a *= R;
    return a;
}

// ============================================================
// ДОПОМІЖНІ ФУНКЦІЇ ДЛЯ ТАБЛИЦІ
// ============================================================

// довжина рядка в символах (а не в байтах), потрібно для UTF-8
int len(const string& s)
{
    int n = 0;
    for (unsigned char c : s)
        if ((c & 0xC0) != 0x80) n++;
    return n;
}

// повторити рядок n разів
string rep(const string& s, int n)
{
    string r;
    for (int i = 0; i < n; i++) r += s;
    return r;
}

// текст по центру в полі шириною w
string center(const string& s, int w)
{
    int total = max(0, w - len(s));
    int left = total / 2;
    return string(left, ' ') + s + string(total - left, ' ');
}

// текст праворуч у полі шириною w (для чисел)
string right(const string& s, int w)
{
    return string(max(0, w - len(s)), ' ') + s;
}

// число -> рядок із заданою кількістю знаків після коми
string num(double v, int prec)
{
    ostringstream os;
    os << fixed << setprecision(prec) << v;
    return os.str();
}

// горизонтальна лінія таблиці (l, m, r - ліві, середні та праві символи рамки)
string hline(const string& l, const string& m, const string& r)
{
    return l + rep("─", WX + 2) + m + rep("─", WL + 2) + m
             + rep("─", WS + 2) + m + rep("─", WN + 2) + r;
}

// верх таблиці разом із рядком заголовків
void printTop()
{
    cout << hline("┌", "┬", "┐") << endl;
    cout << "│ " << center("x", WX)
         << " │ " << center("ln((1+x)/(1-x))", WL)
         << " │ " << center("S", WS)
         << " │ " << center("n", WN) << " │" << endl;
    cout << hline("├", "┼", "┤") << endl;
}

// один рядок даних (S множимо на 2, бо ln(...) = 2 * сума)
void printRow(double x, double s, int n)
{
    cout << "│ " << right(num(x, 2), WX)
         << " │ " << right(num(log((1 + x) / (1 - x)), 5), WL)
         << " │ " << right(num(2 * s, 5), WS)
         << " │ " << right(to_string(n), WN) << " │" << endl;
}

// низ таблиці
void printBottom()
{
    cout << hline("└", "┴", "┘") << endl;
}