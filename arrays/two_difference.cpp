#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int f = -1;
        for (int i = 0, j = 0; i < n && j < n;)
        {
            int diff = arr[i] - arr[j];
            // cout << i << " " << j << endl;
            if (x == diff)
            {
                f = 1;
                break;
            }
            else if (x < diff)
                j++;
            else
                i++;
        }
        cout << f << endl;
    }
}