class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        int arr[n + 5];
        for (int i = 0; i < n + 5; i++)
            arr[i] = 1;
        vector<int> ans;
        for (int i = 2; i <= n; i++)
        {
            if (arr[i] == 1)
            {
                ans.push_back(i);
                for (int j = 2 * i; j <= n; j += i)
                {
                    arr[j] = 0;
                }
            }
        }
        return ans;
    }
};
