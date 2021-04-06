class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++)
            m[s[i]] = i;
        int j = 0, ans = 0;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            ans++;
            j = max(m[s[i]], j);
            if (j <= i)
            {
                res.push_back(ans);
                ans = 0;
                j = i + 1;
            }
        }
        return res;
    }
};