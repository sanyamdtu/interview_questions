#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    int temp[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int lo = 0, hi = ans;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (temp[mid] < arr[i])
            {
                lo = mid + 1;
            }
            else
                hi = mid;
        }
        temp[lo] = arr[i];
        if (lo == ans)
            ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.end());
    cout << lengthOfLIS(arr);
}
