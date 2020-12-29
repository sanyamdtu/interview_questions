#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,p;
	    cin>>n>>p;
	   int e[p][3];
	    for(int i=0;i<p;i++){
	        for(int j=0;j<3;j++)
	            cin>>e[i][j];
	    }
	    int cost[n+1];
        int f=0;
	    for(int k=0;k<n&&f==0;k++){
    	    for(int i=0;i<n+1;i++)
	            cost[i]=INT_MAX;
	        cost[k]=0;
	        for(int l=0;l<n-1;l++){
	            for(int i=0;i<p;i++){
	                if(cost[e[i][0]]==INT_MAX)
	                    continue;
	                if(cost[e[i][1]]>cost[e[i][0]]+e[i][2])
	                    cost[e[i][1]]=cost[e[i][0]]+e[i][2];
	            }
	        }
	   
	        for(int i=0;i<p;i++){
	                if(cost[e[i][0]]==INT_MAX)
	                    continue;
	                if(cost[e[i][1]]>cost[e[i][0]]+e[i][2]){
	                    f=1;
	                    break;
	                }
	                    
	        }
	    }
	    if(f==1&&(n==1&&p==1))
	        cout<<1;
	    else
	        cout<<0;
	    cout<<endl;
	    
	}
	return 0;
}