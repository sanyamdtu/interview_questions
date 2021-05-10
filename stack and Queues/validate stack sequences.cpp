class Solution
{
public:
    bool validateStackSequences(vector<int> &a, vector<int> &b)
    {
        int i = 0, j = 0, n = a.size();
        stack<int> s;
        while (j < n && i < n)
        {
            if (!s.empty() && s.top() == b[j])
            {
                s.pop();
                j++;
            }
            else if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                s.push(a[i]);
                i++;
            }
        }
        while (!s.empty() && j < n && s.top() == b[j])
        {
            s.pop();
            j++;
        }
        return (s.empty());
    }
};