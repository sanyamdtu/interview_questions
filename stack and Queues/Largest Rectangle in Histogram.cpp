class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
    {
        int n = a.size();
        vector<int> arr;
        arr.push_back(0);
        for (auto i : a)
        {
            arr.push_back(i);
        }
        int i = 1;
        arr.push_back(0);
        stack<int> s;
        s.push(0);
        int ans = 0;
        while (i <= n + 1)
        {
            while (!s.empty() && arr[i] < arr[s.top()])
            {
                int a = s.top();
                s.pop();
                ans = max(ans, arr[a] * (i - s.top() - 1));
            }
            if (i != n + 1)
                s.push(i);
            i++;
        }
        return ans;
    }
};