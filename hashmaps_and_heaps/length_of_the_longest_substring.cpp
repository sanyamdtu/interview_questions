class Solution
{
public:
    int longestUniqueSubsttr(string s)
    {
        int n = s.length(), j = 0, i = 0, ans = 1;
        unordered_map<char, int> m;
        while (j < n)
        {
            m[s[j]]++;
            while (m[s[j]] != 1)
                m[s[i++]]--;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};