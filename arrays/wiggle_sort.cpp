class Solution
{
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return;
        int f = 1;
        for (int i = 1; i < n; i++)
        {
            if (f == 1)
            {
                if (arr[i - 1] > arr[i])
                    swap(arr[i - 1], arr[i]);
            }
            else
            {
                if (arr[i - 1] < arr[i])
                    swap(arr[i - 1], arr[i]);
            }
            f = 1 - f;
        }
    }
};