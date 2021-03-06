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
    int p;
    cin >> p;
    priority_queue<int> q;
    int k = 0;
    for (int i = 0, k = 0; i < n; i++)
    {
        q.push(-arr[i]);
        if (q.size() >= p)
        {
            arr[k] = -q.top();
            q.pop();
            k++;
        }
    }
    while (!q.empty())
    {
        arr[k] = -q.top();
        k++;
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}