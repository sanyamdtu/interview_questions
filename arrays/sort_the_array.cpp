#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll arr[n], a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        a[i] = arr[i];
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (arr[i] == a[i])
        i++;
    while (arr[j] == a[j])
        j--;
    int f = 1;
    // cout << i << " " << j << endl;
    int l = i;
    while (i <= j - 1)
    {
        if (arr[i] < arr[i + 1])
        {
            f = 0;
            break;
        }
        i++;
    }
    if (f == 0)
        cout << "no";
    else
    {
        if (l >= j)
            l = j = 0;
        cout << "yes" << endl
             << l + 1 << " " << j + 1;
    }
    cout << endl;
}