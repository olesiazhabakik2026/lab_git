#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
 
using namespace std;
 
int Count(char* str)
{
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ',' && str[i + 1] == '-')
            k++;
    return k;
}
 
char* Change(char* str)
{
    size_t len = strlen(str);
 
    // результат не довший за вхідний рядок: кожна група ",-" (2 символи) стає "*" (1 символ)
    char* tmp = new char[len + 1];
    size_t i = 0;   // індекс у str
    size_t j = 0;   // індекс у tmp
 
    while (str[i] != '\0')
    {
        if (str[i] == ',' && str[i + 1] == '-')
        {
            tmp[j++] = '*';
            i += 2;
        }
        else
            tmp[j++] = str[i++];
    }
    tmp[j] = '\0';
 
    return tmp;
}
 
int main()
{
    char str[101];
 
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
 
    int k = Count(str);
    if (k > 0)
        cout << "String contained " << k << " groups of ',-'" << endl;
    else
        cout << "String contained no groups of ',-'" << endl;
 
    char* dest = Change(str);
 
    cout << "Source string : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
 
    delete[] dest;
 
    return 0;
}
  