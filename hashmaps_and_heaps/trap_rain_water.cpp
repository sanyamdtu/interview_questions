class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return 0;
        int l = 0, r = n - 1, a = 0, b = 0, ans = 0;
        while (l <= r)
        {
            if (arr[l] <= arr[r])
            {
                if (arr[l] >= a)
                    a = arr[l];
                else
                    ans += a - arr[l];
                l++;
            }
            else
            {
                if (arr[r] >= b)
                    b = arr[r];
                else
                    ans += b - arr[r];
                r--;
            }
        }
        return ans;
    }
};