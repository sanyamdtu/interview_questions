typedef long long ll;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        stack<int> s;
        vector<int> ans(n, -1);
        while (i < n)
        {
            while (!s.empty() && arr[i] > arr[s.top()])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
            i++;
        }
        i = 0;
        while (i < n)
        {
            while (!s.empty() && arr[i] > arr[s.top()])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            i++;
        }
        return ans;
    }
};