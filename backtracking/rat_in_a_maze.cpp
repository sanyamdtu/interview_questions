
class Solution
{
public:
    int n;
    vector<string> ans;
    void func(int x, int y, vector<vector<int>> &arr, string &a)
    {
        if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0)
            return;
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(a);
            return;
        }
        arr[x][y] = 0;
        a += 'D';
        func(x + 1, y, arr, a);
        a.pop_back();
        a += 'L';
        func(x, y - 1, arr, a);
        a.pop_back();
        a += 'R';
        func(x, y + 1, arr, a);
        a.pop_back();
        a += 'U';
        func(x - 1, y, arr, a);
        a.pop_back();
        arr[x][y] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int k)
    {
        ans.clear();
        n = k;
        string a = "";
        func(0, 0, m, a);
        return ans;
    }
};
