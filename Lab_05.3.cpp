// Варіант 5
// Вираз: h(r+1) + h^2(r^2+1) + 1
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

const int WR = 9;    // ширина комірки r (без пробілів по краях)
const int WZ = 14;   // ширина комірки z

double h(const double x);

// допоміжні функції для таблиці
int    len(const string& s);
string rep(const string& s, int n);
string center(const string& s, int w);
string right(const string& s, int w);
string num(double v, int prec);
string hline(const string& l, const string& m, const string& r);

int main()
{
    double rp, rk, z;
    int n;

    cout << "rp = "; cin >> rp;
    cout << "rk = "; cin >> rk;
    cout << "n  = "; cin >> n;

    if (n <= 0) {
        cout << "n має бути > 0" << endl;
        return 1;
    }

    double dr = (rk - rp) / n;     // крок розбиття

    // заголовок і шапка таблиці
    cout << endl << "Таблиця значень виразу h(r+1) + h^2(r^2+1) + 1" << endl;
    cout << hline("┌", "┬", "┐") << endl;
    cout << "│ " << center("r", WR) << " │ " << center("z", WZ) << " │" << endl;
    cout << hline("├", "┼", "┤") << endl;

    // n відрізків дають n+1 точок; r = rp + i*dr, щоб не накопичувалась похибка
    for (int i = 0; i <= n; i++)
    {
        double r = rp + i * dr;
        z = h(r + 1) + pow(h(r*r + 1), 2) + 1;

        cout << "│ " << right(num(r, 2), WR)
             << " │ " << right(num(z, 5), WZ) << " │" << endl;
    }

    cout << hline("└", "┴", "┘") << endl;

    return 0;
}

double h(const double x)
{
    if (fabs(x) >= 1 || fabs(x) < 1e-12)       // |x| >= 1 або x = 0
        return (cos(x) + 1) / exp(x);
    else
    {
        double a = x*x;            // перший доданок: x^2 / 1!
        double S = a;
        int j = 0;
        do
        {
            j++;
            double R = pow(x, 4) / ((2*j) * (2*j + 1));   // a_j = a_(j-1) * R
            a *= R;
            S += a;
        } while (j < 6);           // сума для n = 0..6

        return S / (sin(x) * sin(x));
    }
}

// ---------- допоміжні функції для таблиці ----------

// довжина рядка в символах (а не в байтах)
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

// текст праворуч у полі шириною w
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

// горизонтальна лінія таблиці
string hline(const string& l, const string& m, const string& r)
{
    return l + rep("─", WR + 2) + m + rep("─", WZ + 2) + r;
}