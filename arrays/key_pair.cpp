
class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        sort(arr, arr + n);
        for (int i = 0, j = n - 1; i != j;)
        {
            int sum = arr[i] + arr[j];
            if (sum == x)
                return true;
            else if (sum > x)
                j--;
            else
                i++;
        }
        return false;
    }
};
