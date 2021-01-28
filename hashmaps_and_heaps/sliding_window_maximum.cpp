class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        deque<int> q;
        vector<int> ans;
        int n = arr.size();
        for (int j = 0; j < n; j++)
        {
            if (!q.empty() && q.front() == j - k)
                q.pop_front();
            while (!q.empty() && arr[q.back()] <= arr[j])
                q.pop_back();
            q.push_back(j);
            if (j - k + 1 >= 0)
                ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};