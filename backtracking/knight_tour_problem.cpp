#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
int n;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int a = 0;
bool func(int i, int j, int t = 0)
{
    if (i < 0 || j < 0 || i >= n || j >= n || arr[i][j] >= 0)
        return false;
    arr[i][j] = t;
    if (t == (n * n) - 1)
    {
        display();
        return true;
    }
    for (int k = 0; k < 8; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (func(x, y, t + 1) == true)
            return true;
    }
    arr[i][j] = -1;
    return false;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = -1;
        }
    }
    auto a = func(0, 0, 0);
}