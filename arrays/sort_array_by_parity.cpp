class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &arr)
    {
        int n = arr.size(), i = 0, j = 0;
        for (; j < n;)
        {
            if (arr[j] % 2 == 0)
            {
                swap(arr[i++], arr[j]);
                if (i > j)
                    j = i;
            }
            else
            {
                j++;
            }
        }
        return arr;
    }
};