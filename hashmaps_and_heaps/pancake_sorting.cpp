class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        while (n > 0)
        {
            int maxi = -1;
            for (int i = 0; i < n; i++)
            {
                if (maxi == -1)
                    maxi = i;
                else if (arr[maxi] < arr[i])
                    maxi = i;
            }
            if (maxi != n - 1)
            {
                reverse(arr.begin(), maxi + arr.begin() + 1);
                ans.push_back(maxi + 1);
                ans.push_back(n);
                reverse(arr.begin(), n - 1 + arr.begin() + 1);
            }
            n--;
        }
        return ans;
    }
};