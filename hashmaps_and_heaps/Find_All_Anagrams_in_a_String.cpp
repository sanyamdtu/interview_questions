class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.length() > s.length())
            return ans;
        int cnt = 0;
        unordered_map<char, int> t, m;
        for (auto i : p)
            t[i]++;
        int i = 0, j = 0;
        for (; j < p.length(); j++)
        {
            if (m[s[j]] < t[s[j]])
                cnt++;
            m[s[j]]++;
        }
        if (p.length() == cnt)
            ans.push_back(0);
        while (j < s.length())
        {
            if (m[s[j]] < t[s[j]])
                cnt++;
            m[s[j]]++;
            j++;
            m[s[i]]--;
            if (m[s[i]] < t[s[i]])
                cnt--;
            i++;
            if (p.length() == cnt)
                ans.push_back(i);
        }
        return ans;
    }
};