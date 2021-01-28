
//User function template for C++

class Solution
{
public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    int maxRepeating(int *arr, int n, int k)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == i || arr[arr[i]] == arr[i])
                continue;
            swap(arr[i], arr[arr[i]]);
            i--;
        }
        for (int i = 0; i < n; i++)
            if (arr[i] == i)
                arr[i] = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
                arr[arr[i]]--;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
            mini = min(arr[i], mini);
        for (int i = 0; i < n; i++)
            if (arr[i] == mini)
                return i;
        return 1;
    }
};
/*
// another solution
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % k] += k;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans)
            return (arr[i] % k);
    }
*/