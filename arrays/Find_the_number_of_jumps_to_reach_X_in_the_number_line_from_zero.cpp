#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    long long temp = 0;
    long long i = 1;
    for (; i <= x; i++)
    {
        temp = (i * (i + 1)) / 2;
        if (temp >= x)
            break;
    }
    int diff = temp - x;
    if (diff % 2 == 1)
    {
        i++;
        temp = (i * (i + 1)) / 2;
        diff = temp - x;
        if (diff % 2 == 1)
            i++;
    }
    cout << i;
}