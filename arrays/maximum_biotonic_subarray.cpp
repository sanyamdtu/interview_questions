#include <bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i] = 1;
    }
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            c++;
        }
        else
        {
            c = 1;
        }
        a[i] = c;
    }
    c = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {

            c++;
        }
        else
        {
            c = 1;
        }

        b[i] = c;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] + b[i] - 1);
    }
    cout << ans;
}