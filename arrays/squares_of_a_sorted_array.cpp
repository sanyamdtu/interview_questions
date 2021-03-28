class Solution
{
public:
    vector<int> sortedSquares(vector<int> &arr)
    {
        vector<int> v;
        for (int i = 0, j = arr.size() - 1; i <= j;)
        {
            long long a = arr[i] * arr[i];
            long long b = arr[j] * arr[j];
            v.push_back(max(a, b));
            if (a < b)
                j--;
            else
                i++;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};