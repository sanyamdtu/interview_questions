class Solution
{
public:
    int subarraysDivByK(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
        }
        m[0] = 1;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            ans += m[(k + (arr[j] % k)) % k];
            m[(k + (arr[j] % k)) % k]++;
        }
        return ans;
    }
};