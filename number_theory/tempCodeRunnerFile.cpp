#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp;
        cin >> n;
        temp = n;
        vector<int> v;
        for (int i = 2; i <= sqrt(temp) + 1; i++)
        {
            if (n % i == 0)
                v.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
        // cout << temp;
        int ans = temp;
        for (auto i : v)
        {
            // cout << ans << " ";
            int a = ans / i;
            ans = ans - a;
        }
        if (v.empty() && temp != 1)
            ans--;
        cout << ans << endl;
    }
}