class Solution
{
public:
    string removeDuplicateLetters(string a)
    {
        unordered_map<char, int> m, p;
        for (auto i : a)
        {
            m[i]++;
        }
        stack<char> s;
        for (auto i : a)
        {
            while (p[i] == 0 && !s.empty() && i < s.top() && m[s.top()] > 0)
            {
                p[s.top()] = 0;
                s.pop();
            }
            if (p[i] == 0)
            {
                p[i] = 1;
                s.push(i);
            }
            m[i]--;
        }
        string ans = "";
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};