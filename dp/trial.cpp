#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, float *wt, float *val)
{
    float dp[1001];

    int max_index = -1;
    float maximum = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = (val[i] / wt[i]);
        if (dp[i] > maximum)
        {
            maximum = dp[i];
            max_index = i;
        }
    }

    int ans = 0;
    int now_index = max_index;
    float now_maximum = 0;

    for (int i = 0; i < n; i++)
    {

        if (w >= wt[now_index])
        {

            while (w > 0)
            {
                w = w - wt[now_index];
                ans += val[now_index];
            }

            if (w == 0)
            {
                break;
            }

            w = w + wt[now_index];
            ans -= val[now_index];
        }

        for (int i = 0; i < n; i++)
        {
            if (dp[i] > now_maximum and dp[i] < maximum)
            {
                now_maximum = dp[i];
                now_index = i;
            }
        }
        maximum = now_maximum;
        now_maximum = 0;
    }

    return ans;
}

int main()
{
    int n, w;
    cin >> n >> w;

    float *wt = new float[n];
    float *val = new float[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << knapsack(n, w, wt, val);

    return 0;
}