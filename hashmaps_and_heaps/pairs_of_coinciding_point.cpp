
class Solution
{
public:
    int numOfPairs(int x[], int y[], int n)
    {
        unordered_map<int, int> r, c;
        unordered_map<string, int> m;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string a = to_string(x[i]) + "#" + to_string(y[i]);
            ans += r[x[i]] + c[y[i]] - 2 * m[a];
            m[a]++;
            r[x[i]]++;
            c[y[i]]++;
        }
        return ans;
    }
};
