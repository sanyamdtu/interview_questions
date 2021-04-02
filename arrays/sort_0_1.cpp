
class Solution
{
public:
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int arr[], int n)
    {
        if (n == 0)
            return;
        int i = 0, j = 0;
        for (j = 0; j < n;)
        {
            if (arr[j] == 0)
                swap(arr[i++], arr[j]);
            if (j < i)
                j = i;
            else
                j++;
        }
    }
};
