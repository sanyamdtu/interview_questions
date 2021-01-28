#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n)
{
    for (int i = n; i >= 1; i--)
    {
        int idx = i;
        while (1)
        {
            int l = idx * 2;
            int r = 2 * idx + 1;
            if (l <= n && r <= n && arr[idx] > min(arr[l], arr[r]))
            {
                if (arr[l] < arr[r])
                {
                    swap(arr[l], arr[idx]);
                    idx = l;
                }
                else
                {
                    swap(arr[r], arr[idx]);
                    idx = r;
                }
            }
            else if (l <= n && r > n && arr[idx] > arr[l])
            {
                swap(arr[l], arr[idx]);
                idx = l;
            }
            else if (l > n && r <= n && arr[idx] > arr[r])
            {
                swap(arr[r], arr[idx]);
                idx = r;
            }
            else
                break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    heapify(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}