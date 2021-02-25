#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k, x;
    cin >> k >> x;
    int i;
    for (i = 0; i < n;)
    {
        if (arr[i] == x)
            break;
        int diff = abs(x - arr[i]);
        i += max((diff / k), 1);
    }
    cout << i;
}