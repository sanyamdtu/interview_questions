class Solution
{
public:
    int numRescueBoats(vector<int> &arr, int x)
    {
        int temp = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0, j = n - 1; i < j;)
        {
            int sum = arr[i] + arr[j];
            if (sum <= x)
            {
                temp++;
                j--;
            }
            else
                i++;
        }
        return n - temp;
    }
};