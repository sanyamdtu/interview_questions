class Solution
{
public:
    int firstMissingPositive(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i <= n;)
        {
            int idx = i - 1;
            if (arr[idx] > 0 && arr[idx] <= n && arr[idx] != arr[arr[idx] - 1])
            {
                swap(arr[idx], arr[arr[idx] - 1]);
            }
            else
                i++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i - 1] != i)
                return i;
        }
        return n + 1;
    }
};