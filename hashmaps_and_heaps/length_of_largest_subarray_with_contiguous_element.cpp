#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int maxi = arr[i], mini = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            maxi = max(maxi, arr[j]);
            mini = min(mini, arr[j]);
            if (maxi - mini == j - i)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
}