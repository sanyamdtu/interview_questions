class Solution
{
public:
    string removeKdigits(string a, int k)
    {
        int i = 0, n = a.length();
        stack<char> s;
        while (i < n)
        {
            if (!s.empty() && a[i] < s.top() && k > 0)
            {
                s.pop();
                i--;
                k--;
            }
            else
                s.push(a[i]);
            i++;
        }
        string ans = "";
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        int p = ans.length();
        string q = ans.substr(0, max(p - k, 0));
        int j = 0;
        while (j < p - k && q[j] == '0')
            j++;
        string res = q.substr(j, max(p - k - j, 0));
        if (res == "")
            return "0";
        return res;
    }
};