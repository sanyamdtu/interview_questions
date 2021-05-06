class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       stack<int> s;
       vector<int> ans(n,1);
       int i=n-1;
       while(i>=0){
           while(!s.empty()&&arr[i]>arr[s.top()]){
               ans[s.top()]=s.top()-i;
               s.pop();
           }
           s.push(i);
           i--;
       }
       while(!s.empty()){
           ans[s.top()]=s.top()+1;
           s.pop();
       }
       return ans;
    }
};

