#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a[] = {1, 5, 10, 20, 40, 80}, b[] = {6, 7, 20, 80, 100}, c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(a) / sizeof(a[0]), n2 = sizeof(b) / sizeof(b[0]), n3 = sizeof(c) / sizeof(c[0]);
    int i = 0, j = 0, k = 0;
    vector<int> v;
    while (i < n1 && j < n2 && k < n3)
    {
        int ans = min(a[i], min(b[j], c[k]));
        if (a[i] == b[j] && a[i] == c[k])
            v.push_back(a[i]);
        if (ans == a[i])
            i++;
        else if (ans == b[j])
            j++;
        else
            k++;
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
}