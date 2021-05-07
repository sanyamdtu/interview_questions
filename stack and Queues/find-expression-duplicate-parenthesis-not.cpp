#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int i = 0, n = a.length();
    stack<char> s;
    int f = 1;
    while (i < n)
    {
        if (a[i] == ')')
        {
            if (s.top() == '(')
            {
                f = 0;
                break;
            }
            else
            {
                while (s.top() != '(')
                    s.pop();
                s.pop();
            }
        }
        else
            s.push(a[i]);
        i++;
    }
    if (f == 0)
        cout << "YES";
    else
        cout << "NO";
}