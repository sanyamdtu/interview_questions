
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
