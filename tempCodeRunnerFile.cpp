#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    set<int> x, y;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
            x.insert(i);
    }
    for (int i = 1; i <= b; i++)
    {
        if (b % i == 0)
            y.insert(i);
    }
    int c = 1;
    for (auto i : x)
    {

        if (i == *(y.begin()))
        {
            c = i;
            k--;
            if (k == 0)
                break;
            y.erase(y.begin());
        }
    }
    cout << c;
}