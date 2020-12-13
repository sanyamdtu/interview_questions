class Solution {
public:
    double func(string a,string b,unordered_map<string,vector<pair<string,double>>> &g,unordered_map<string,double> vis){
        int f=0;
        for(auto i:g){
            if(i.first==a)
                f++;
            if(i.first==b)
                f++;
        }
        if(f!=2)
            return -1.0;
        if(a==b)
            return 1.0; 
        
        queue<pair<string,double>> q;
        q.push({a,1});
        while(!q.empty()){
            auto p=q.front();
            if(p.first==b)
                return p.second;
            q.pop();
            for(auto i:g[p.first]){
                if(vis[i.first]==0){
                    q.push({i.first,(p.second*i.second)});
                    vis[i.first]=1;
                }
            }
            
        }
        return (-1.0);
    }
    vector<double> calcEquation(vector<vector<string>>& arr, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>>> g;
        for(int i=0;i<arr.size();i++){
            g[arr[i][0]].push_back({arr[i][1],v[i]});
            g[arr[i][1]].push_back({arr[i][0],(double)(1.0000/v[i])});
        }
        vector<double> ans;
        for(auto i:q){
            unordered_map<string,double> vis;
            vis[i[0]]=1;
            ans.push_back(func(i[0],i[1],g,vis));
        }
        return ans;
    }
};