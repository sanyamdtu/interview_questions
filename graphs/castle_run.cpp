#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int in[n];
	    memset(in,0,sizeof(in));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int a;
	            cin>>a;
	            if(a==1)
	                in[i]++;
	        }
	    }
	    int f=0;
	    for(int i=0;i<n;i++){
	        if(in[i]%2==1||in[i]==0)
	            f=1;
	    }
	    if(f==0||n==1)
	        cout<<"True";
	    else
	        cout<<"False";
	    cout<<endl;
	}
	return 0;
}