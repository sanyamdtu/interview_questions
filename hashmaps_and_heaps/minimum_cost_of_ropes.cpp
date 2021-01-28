// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

typedef long long ll;
long long minCost(long long arr[], long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 0;
    if (n == 2)
        return arr[0] + arr[1];
    ll ans = 0, l;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++)
        q.push(-arr[i]);
    while (q.size() != 1)
    {
        l = q.top();
        q.pop();
        l += q.top();
        q.pop();
        ans += l;
        q.push(l);
    }
    return -ans;
}
