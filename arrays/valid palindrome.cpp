class Solution
{
public:
    bool validPalindrome(string s)
    {
        int n = s.length();
        int f = 2, i = 0, j = n - 1;
        while (f >= 1 && i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                f--;
                i++;
            }
        }
        if (f >= 1)
            return true;
        f = 2, i = 0, j = n - 1;
        while (f >= 1 && i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                f--;
                j--;
            }
        }
        if (f >= 1)
            return true;
        return false;
    }
};