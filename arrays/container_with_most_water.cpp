class Solution
{
public:
    int maxArea(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j;)
        {
            ans = max(ans, (j - i) * (min(arr[i], arr[j])));
            if (arr[i] < arr[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};