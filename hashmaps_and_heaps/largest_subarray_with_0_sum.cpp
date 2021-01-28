
/*You are required to complete this function*/

int maxLen(int arr[], int n)
{
    unordered_map<int, int> m;
    int ans = 0;
    m[0] = -1;
    m[arr[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
        if (m.find(arr[i]) == m.end())
            m[arr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
        {
            ans = max(i - m[arr[i]], ans);
        }
    }
    return ans;
}
