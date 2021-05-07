class Solution
{
public:
    int minAddToMakeValid(string a)
    {
        int n = a.length(), i = 0;
        stack<char> s;
        while (i < n)
        {
            if (!s.empty() && a[i] == ')' && s.top() == '(')
                s.pop();
            else
                s.push(a[i]);
            i++;
        }
        return s.size();
    }
};