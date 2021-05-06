class Solution
{
public:
    bool isValid(string a)
    {
        int i = 0;
        int n = a.length();
        stack<int> s;
        while (i < n)
        {
            if (!s.empty())
            {
                if (a[i] == '}')
                {
                    if (s.top() != '{')
                        return false;
                    s.pop();
                }
                else if (a[i] == ']')
                {
                    if (s.top() != '[')
                        return false;
                    s.pop();
                }
                else if (a[i] == ')')
                {
                    if (s.top() != '(')
                        return false;
                    s.pop();
                }
                else
                    s.push(a[i]);
            }
            else
                s.push(a[i]);

            i++;
        }
        return s.empty();
    }
};