class Solution
{
public:
    //Function to find the largest number after k swaps.
    int n;
    string s;
    string ans;
    bool func(string a, string b)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
        }
        return true;
    }
    void func(int i, int k)
    {
        if (i == n || k == 0)
        {
            if (func(s, ans))
                ans = s;
            return;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] < s[j])
            {
                swap(s[i], s[j]);
                func(i + 1, k - 1);
                swap(s[i], s[j]);
            }
        }
        func(i + 1, k);
    }
    string findMaximumNum(string a, int k)
    {
        n = a.length();
        s = a;
        ans = a;
        func(0, k);
        return ans;
    }
};
