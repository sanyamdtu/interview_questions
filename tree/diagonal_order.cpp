#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define mod 1000000007
#define INF 1e18
typedef  long long ll;

vector<vector<int>> diagonal_order(node * root){
	vector<vector<int>> v;
	queue<pair<node * ,int>> q;
	map<int,vector<int>> m;
	q.push({root,0});
	while(!q.empty()){
		int size=q.size();
		while(size){
			auto a=q.front();
			q.pop();
			node * temp=a.first;
			int d=a.second;
			m[d].push_back(a->val);
			if(temp->left){
				q.push({temp->left,d-1});
			}
			if(temp->right){
				q.push({temp->right,d});
			}
			size--;
		}
	}
	for(auto i:m){
		v.push_back(i.second);
	}
}