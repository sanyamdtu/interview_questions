class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        for (int i = 0, j = 0; i < n;)
        {
            if (arr[i] < 0)
            {
                swap(arr[i], arr[j]);
                j++;
                if (i < j)
                    i = j;
            }
            else
                i++;
        }
        int j = 0;
        while (j < n && arr[j] < 0)
            j++;
        for (int i = 0; i < n && j < n; i++)
        {
            if (i % 2 == 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};
