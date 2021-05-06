class Solution
{
public:
    /*You are required to complete this method */
    int findMaxDiff(int arr[], int n)
    {
        int ans = 0;
        stack<int> s;
        int i = 0;
        while (i < n)
        {
            while (!s.empty() && arr[i] < arr[s.top()])
            {
                int a = s.top();
                s.pop();
                if (s.empty())
                    ans = max(ans, abs(arr[i] - 0));
                else
                    ans = max(ans, abs(arr[i] - arr[s.top()]));
            }
            if (s.empty() || arr[s.top()] != arr[i])
                s.push(i);
            i++;
        }
        while (!s.empty())
        {
            int a = s.top();
            s.pop();
            if (s.empty())
                ans = max(ans, 0);
            else
                ans = max(ans, abs(0 - arr[s.top()]));
        }
        return ans;
    }
};
