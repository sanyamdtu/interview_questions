class Solution
{
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s)
    {
        unordered_map<char, int> m;
        int n = s.length(), i = 0, j = 0, c = 0, ans = 0;
        while (j < n)
        {
            m[s[j]]++;
            if (m[s[j]] == 1)
                c++;
            while (c > 2)
            {
                m[s[i]]--;
                if (m[s[i++]] == 0)
                    c--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};