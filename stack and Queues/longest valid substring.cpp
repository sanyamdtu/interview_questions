class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length(), ans = 0, curr = 0, l = 0;
        for (auto i : s)
        {
            if (i == '(')
            {
                curr++;
                l++;
            }
            else
            {
                curr--;
                l++;
                if (curr < 0)
                {
                    l = 0;
                    curr = 0;
                }
                if (curr == 0)
                    ans = max(ans, l);
            }
        }
        curr = 0, l = 0;
        reverse(s.begin(), s.end());
        // cout<<s;
        for (auto i : s)
        {
            if (i == ')')
            {
                curr++;
                l++;
            }
            else
            {
                curr--;
                l++;
                if (curr < 0)
                {
                    l = 0;
                    curr = 0;
                }
                if (curr == 0)
                    ans = max(ans, l);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int findMaxLen(string p)
    {
        stack<int> s;
        string a = ")";
        a += p;
        a += '(';
        int n = a.length(), i = 1;
        int ans = 0;
        s.push(0);
        while (i <= n + 1)
        {
            if (!s.empty())
            {
                if (a[i] == ')')
                {
                    if (a[s.top()] == '(')
                    {
                        s.pop();
                        ans = max(ans, i - s.top());
                    }
                    else
                        s.push(i);
                }
                else
                    s.push(i);
            }
            else
            {
                s.push(i);
            }
            i++;
        }
        return ans;
    }
};
