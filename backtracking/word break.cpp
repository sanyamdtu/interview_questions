
class Solution
{
public:
    unordered_map<string, int> m;
    string s;
    int n;
    vector<string> ans;
    bool func(int i, string &res)
    {
        if (i == n)
        {
            ans.push_back(res);
            return false;
        }
        string a = "";
        for (int j = i; j < n; j++)
        {
            a += s[j];
            if (m[a] == 1)
            {
                string q = res;
                if (res == "")
                    res = a;
                else
                    res += " " + a;
                if (func(j + 1, res))
                    return true;
                res = q;
            }
        }
        return false;
    }
    vector<string> wordBreak(int e, vector<string> &p, string a)
    {
        m.clear();
        vector<string> temp;
        ans = temp;
        s = a;
        string t = "";
        n = a.length();
        for (auto i : p)
            m[i] = 1;
        auto q = func(0, t);
        return ans;
    }
};
