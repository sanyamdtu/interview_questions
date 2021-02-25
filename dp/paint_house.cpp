class Solution
{
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int k = arr[0].size();
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            if (min1 > arr[0][i])
            {
                min2 = min1;
                min1 = arr[0][i];
            }
            else if (min2 > arr[0][i])
                min2 = arr[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (arr[i - 1][j] == min1)
                {
                    arr[i][j] += min2;
                }
                else
                    arr[i][j] += min1;
            }
            min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                if (min1 > arr[i][j])
                {
                    min2 = min1;
                    min1 = arr[i][j];
                }
                else if (min2 > arr[i][j])
                    min2 = arr[i][j];
            }
        }
        return min1;
    }
};