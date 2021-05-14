class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int k)
    {
        int i = 0, j = 0, sum = 0, f = 0;
        while (j < n)
        {
            sum += arr[j];
            while (sum > k && i <= j)
                sum -= arr[i++];
            if (sum == k)
            {
                f = 1;
                break;
            }
            j++;
        }
        vector<int> ans;
        if (f == 0)
        {
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        return ans;
    }
};
