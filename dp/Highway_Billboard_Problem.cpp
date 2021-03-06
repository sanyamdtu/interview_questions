#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5, t = 5, m = 20;
    int x[] = {6, 7, 12, 13, 14};
    int r[] = {5, 6, 5, 3, 1};
    int arr[m + 1];
    memset(arr, 0, sizeof(arr));
    int j = 0;
    for (int i = 1; i <= m; i++)
    {
        if (j < n && x[j] == i)
        {
            arr[i] = r[j];
            arr[i] = max(arr[i], max(arr[i - 1], arr[i - t - 1] + r[j]));
            j++;
        }
        else
            arr[i] = arr[i - 1];
    }
    cout << arr[m];
}