class Solution
{
public:
    string multiply(string s, string t)
    {
        if (s == "0" || t == "0")
            return "0";
        int n = s.length(), m = t.length();
        int arr[n + m];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int idx = i + j + 1;
                int temp = (s[i] - '0') * (t[j] - '0');
                arr[idx] += temp;
            }
        }
        for (int j = n + m - 1; j >= 1; j--)
        {

            arr[j - 1] += arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        int i = 0;
        while (i < n + m && arr[i] == 0)
        {
            i++;
        }
        string ans = "";
        for (; i < n + m; i++)
        {
            ans.push_back(arr[i] + '0');
        }
        return ans;
    }
};