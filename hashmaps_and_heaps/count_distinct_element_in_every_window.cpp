
vector<int> countDistinct(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int c = 0;
    vector<int> ans;
    for (int j = 0, i = 0; j < n; j++)
    {
        m[arr[j]]++;
        if (m[arr[j]] == 1)
            c++;
        if (j - i + 1 == k)
        {
            ans.push_back(c);
            m[arr[i]]--;
            if (m[arr[i]] == 0)
                c--;
            i++;
        }
    }
    return ans;
}