#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n = 12, m = 10;
int func(int i, int j, int arr[100][100])
{

    if (i == n - 1)
        return 0;
    arr[i][j] = -1;
    int ans = 1000;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == 1)
            ans = min(func(i + dx[k], j + dy[k], arr), ans);
    }
    arr[i][j] = 1;
    return ans + 1;
}
int main()
{

    int arr[100][100] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << arr[i][j] << " ";
            if (arr[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < n && y < m)
                        arr[x][y] = 2;
                }
            }
            // cout << endl;
        }
    }
    int ans = 2000;

    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == 1)
            ans = min(ans, func(0, i, arr));
    }
    cout << ans;
}