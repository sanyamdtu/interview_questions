class Solution
{
public:
    int jump(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0 || n == 1)
            return 0;
        int curr_max = 0, next_max = 0, jump = 0;
        for (int i = 0; i < n; i++)
        {
            next_max = max(next_max, i + arr[i]);
            if (next_max >= n - 1)
                return jump + 1;
            if (i == curr_max)
            {
                curr_max = next_max;
                jump++;
            }
        }
        return jump;
    }
};