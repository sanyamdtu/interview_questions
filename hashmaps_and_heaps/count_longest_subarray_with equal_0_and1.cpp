class Solution
{
public:
    int findMaxLength(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int a[n], b[n];
        if (arr[0] == 0)
        {
            a[0] = 1;
            b[0] = 0;
        }
        else
        {
            b[0] = 1;
            a[0] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
            if (arr[i] == 0)
                a[i]++;
            else
                b[i]++;
        }
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (m.find(a[i] - b[i]) != m.end())
            {
                ans = max(i - m[a[i] - b[i]], ans);
            }
            else
                m[a[i] - b[i]] = i;
        }
        return ans;
    }
};