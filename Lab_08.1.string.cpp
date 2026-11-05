#include <iostream>
#include <string>
 
using namespace std;
 
int Count(const string s)
{
    int    k = 0;
    size_t pos = 0;
    while ((pos = s.find(',', pos)) != string::npos)
    {
        pos++;
        if (pos < s.size() && s[pos] == '-')
            k++;
    }
 
    return k;
}
 
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find(',', pos)) != string::npos)
        if (pos + 1 < s.size() && s[pos + 1] == '-')
            s.replace(pos, 2, "*");
        else
            pos++;
 
    return s;
}
 
int main()
{
    string str;
 
    cout << "Enter string:" << endl;
    getline(cin, str);
 
    cout << "String contained " << Count(str) << " groups of ',-'" << endl;
 
    string dest = Change(str);
 
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
 
    return 0;
}
 