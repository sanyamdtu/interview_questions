class Solution
{
public:
    int maxDistToClosest(vector<int> &arr)
    {
        int i = 0, curr = 0, ans = -1, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                if (ans == -1)
                    ans = max(ans, curr);
                else
                    ans = max(ans, (curr + 1) / 2);
                curr = 0;
            }
            else
                curr++;
        }
        ans = max(ans, curr);
        return max(ans, 0);
    }
};