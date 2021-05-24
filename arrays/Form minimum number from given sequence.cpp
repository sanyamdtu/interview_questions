
class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        string ans = "";
        int n = s.length();
        int vis[10];
        memset(vis, 0, sizeof(vis));
        int i = -1, c = 0;
        for (; i < n;)
        {
            int j = i + 1;
            while (j < n && s[j] == 'D')
            {
                c++;
                j++;
            }
            i = j;
            int k = 1;
            c++;
            while (1)
            {
                if (vis[k] == 0)
                    c--;
                if (c == 0)
                    break;
                k++;
            }
            while (k >= 1)
            {
                if (vis[k] == 0)
                {
                    ans += '0' + k;
                    vis[k] = 1;
                }
                k--;
            }
        }
        return ans;
    }
};
