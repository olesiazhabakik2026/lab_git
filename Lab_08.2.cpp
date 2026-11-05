// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// Відомо, що серед цих символів є хоча б один, відмінний від пробілу.
// Варіант 5:
// Видалити групи пробілів, якими починається і якими закінчується рядок,
// а також замінити кожну внутрішню групу пробілів одним пробілом.
// Якщо вказаних груп немає в цьому рядку, то залишити рядок без змін.
 
#include <iostream>
#include <string>
 
using namespace std;
 
string Change(string& s)
{
    size_t first = s.find_first_not_of(' ');
    if (first == string::npos)          // рядок із самих пробілів (за умовою не трапляється)
        return s;
 
    size_t last = s.find_last_not_of(' ');
 
    s.erase(last + 1);                  // група пробілів у кінці рядка
    s.erase(0, first);                  // група пробілів на початку рядка
 
    size_t start = 0,
           finish;
    while ((start = s.find_first_of(' ', start)) != string::npos)
    {
        finish = s.find_first_not_of(' ', start + 1);   // перший не пробіл після групи
        s.replace(start, finish - start, " ");          // група пробілів -> один пробіл
        start++;
    }
 
    return s;
}
 
int main()
{
    string str;
 
    cout << "Enter string:" << endl;
    getline(cin, str);
 
    string dest = Change(str);
 
    cout << "Modified string (param) : [" << str  << "]" << endl;
    cout << "Modified string (result): [" << dest << "]" << endl;
 
    return 0;
}
 