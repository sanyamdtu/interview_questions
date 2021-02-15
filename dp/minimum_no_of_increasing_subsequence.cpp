#include <bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {8, 4, 1, 4, 2, 9, 2, 9};
    int n = sizeof(arr) / sizeof(int);
    int ans = 0;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        int lo = 0, hi = ans, k = INT_MAX;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid == ans)
                break;
            if (temp[mid] < arr[i])
            {
                hi = mid - 1;
                k = min(k, mid);
            }
            else
                lo = mid + 1;
        }
        if (k == INT_MAX)
            k = ans;
        temp[k] = arr[i];
        if (k == ans)
            ans++;
    }
    cout << ans;
}