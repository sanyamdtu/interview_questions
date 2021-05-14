#include <bits/stdc++.h>
using namespace std;
int n;
int ans = INT_MAX;
void func(int i, vector<int> &a, vector<int> &b, int arr[])
{
    if (i == n)
    {
        if (!a.empty() && !b.empty())
        {
            int p = 0, q = 0;
            for (auto i : a)
                p += i;
            for (auto i : b)
                q += i;
            ans = min(ans, abs(p - q));
        }
        return;
    }
    a.push_back(arr[i]);
    func(i + 1, a, b, arr);
    a.pop_back();
    b.push_back(arr[i]);
    func(i + 1, a, b, arr);
    b.pop_back();
}
int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    vector<int> a, b;
    func(0, a, b, arr);
    cout << ans;
}