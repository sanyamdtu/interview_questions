class Solution
{
public:
    int ans = 0;
    int longestOnes(vector<int> &arr, int k)
    {
        int i = 0, j = 0, n = arr.size();
        while (j < n)
        {
            if (arr[j] == 0)
                k--;
            while (k < 0)
            {
                if (arr[i] == 0)
                    k++;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};