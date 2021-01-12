
class Solution
{
public:
    bool checkIsAP(int arr[], int n)
    {
        unordered_map<int, int> m;
        int a = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            a = min(a, arr[i]);
            m[arr[i]]++;
        }
        int f = 0;
        int b = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != a || f == 1)
                b = min(arr[i], b);
            else if (f == 0)
                f = 1;
        }
        m[a]--;
        m[b]--;
        int d = b - a;
        for (int i = 2; i < n; i++)
        {
            b += d;
            m[b]--;
        }
        int ans = 1;
        for (auto i : m)
        {
            if (i.second != 0)
            {
                ans = 0;
                break;
            }
        }
        return (ans == 1);
    }
};
