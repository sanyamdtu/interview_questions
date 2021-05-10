
typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{
    vector<long long> ans;
    int i = n - 1, p = -1;
    while (i > n - k)
    {
        if (arr[i] < 0)
            p = i;
        i--;
    }
    for (int j = n - 1; j >= 0; j--)
    {
        i = j - k + 1;
        if (i >= 0)
        {
            if (arr[i] < 0)
                p = i;
            if (p == -1)
                ans.push_back(0);
            else
                ans.push_back(arr[p]);
        }
        if (p == j)
            p = -1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}