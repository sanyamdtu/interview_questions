class Solution
{
public:
    int firstMissingPositive(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 1;
        arr.push_back(arr[0]);
        for (int i = 1; i <= n;)
        {
            if (arr[i] != i)
            {
                if (arr[i] < 1 || arr[i] > n)
                    i++;
                else if (arr[i] != arr[arr[i]])
                    swap(arr[i], arr[arr[i]]);
                else
                    i++;
            }
            else
                i++;
        }
        for (int i = 1; i <= n; i++)
            if (arr[i] != i)
                return i;
        return n + 1;
    }
};