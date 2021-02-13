#include <bits/stdc++.h>
using namespace std;
int temp[1000];
void merge(int arr[], int s, int mid, int e)
{
    int i = s, j = mid + 1;
    int n = e - s + 1, c = 0;
    while (i < mid + 1 && j <= e)
    {
        if (arr[i] < arr[j])
            temp[c++] = arr[i++];
        else
            temp[c++] = arr[j++];
    }
    while (i < mid + 1)
        temp[c++] = arr[i++];
    while (j <= e)
        temp[c++] = arr[j++];
    c = 0;
    i = s;
    while (c < n)
        arr[i++] = temp[c++];
}
void mergesort(int arr[], int n, int s, int e)
{
    if (s >= e)
        return;
    cout << s << " " << e << endl;
    int mid = s + (e - s) / 2;
    mergesort(arr, n, s, mid);
    mergesort(arr, n, mid + 1, e);
    merge(arr, s, mid, e);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, n, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}