class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        stack<int> s;
        vector<int> ans(n,0);
        while(i<n){
            while(!s.empty()&&arr[i]>arr[s.top()]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
            i++;
        }
        return ans;
    }
};