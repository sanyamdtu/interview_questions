#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int b = 1, e = 1;
    for (int i = 1; i < n; i++)
    {
        int temp = e;
        e = b + e;
        b = temp;
    }
    cout << (b + e) * (b + e);
}