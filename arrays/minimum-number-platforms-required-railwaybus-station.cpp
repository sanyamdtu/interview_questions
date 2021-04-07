
class Solution
{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int ans = 0, curr = 0;
        for (int i = 0, j = 0; i < n && j < n;)
        {
            if (arr[i] <= dep[j])
            {
                curr++;
                i++;
            }
            else
            {
                j++;
                curr--;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
