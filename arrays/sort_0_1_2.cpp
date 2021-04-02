class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0, j = 0, k = n - 1;
        while (j <= k)
        {
            if (arr[j] == 0)
            {
                swap(arr[i++], arr[j]);
                if (i > j)
                    j = i;
            }
            else if (arr[j] == 1)
            {
                j++;
            }
            else
            {
                swap(arr[j], arr[k]);
                k--;
            }
        }
    }
};