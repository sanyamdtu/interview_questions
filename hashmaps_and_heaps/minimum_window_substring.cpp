class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> m, p;
        int cnt = 0;
        int j = 0, i = 0;
        string ans = s;
        for (auto i : t)
            p[i]++;
        int f = 0;
        for (; j < s.length(); j++)
        {
            if (m[s[j]] < p[s[j]])
                cnt++;
            m[s[j]]++;
            while (cnt == t.length())
            {
                f = 1;
                if (ans.length() > j - i + 1)
                    ans = s.substr(i, j - i + 1);
                m[s[i]]--;
                if (m[s[i]] < p[s[i]])
                    cnt--;
                i++;
            }
        }
        if (ans == s && f == 0)
            ans = "";
        return ans;
        j++;
    }
};