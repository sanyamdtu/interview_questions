class Solution
{
public:
    vector<vector<string>> ans;
    string s;
    int n;
    void func(vector<string> &res, int i)
    {
        if (i == n)
        {
            ans.push_back(res);
            return;
        }
        string a = "";
        for (int j = i; j < n; j++)
        {
            a += s[j];
            int f = 0;
            for (int k = 0, l = a.length() - 1; k <= l; k++, l--)
            {
                if (a[k] != a[l])
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                res.push_back(a);
                func(res, j + 1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string a)
    {
        s = a;
        n = a.length();
        ans.clear();
        vector<string> q;
        func(q, 0);
        return ans;
    }
};