/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int find(int x,int par[]){
        if(par[x]==x)
            return x;
        return par[x]=find(par[x],par);
    }
    void un(int x,int y,int r[],int par[]){
        int px=find(x,par);
        int py=find(y,par);
        if(r[px]>r[py]){
            par[py]=px;
        }
        else if(r[px]==r[py]){
            r[px]++;
            par[py]=px;
        }
        else{
            par[px]=py;
        }
    }
    vector<int> numIslands2(int n, int m, vector<Point> a) {
        int par[n*m+1115];
        int r[n*m+1115];
        int arr[n][m];
        vector<int> v;
        memset(arr,0,sizeof(arr));
        memset(r,1,sizeof(r));
        for (int i = 0; i <= n*m; i++) {
            par[i]=i;
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        int ans=0;
        for(auto i:a){
            if(arr[i.x][i.y]==1)
                ans--;
            arr[i.x][i.y]=1;
            ans++;
            
            for(int j=0;j<4;j++){
                int x=i.x+dx[j];
                int y=i.y+dy[j];
                if(x>=0&&y>=0&&x<n&&y<m&&arr[x][y]==1){
                    int c=i.x*m+i.y;
                    int d=x*m+y;
                    if(find(c,par)!=find(d,par)){                        un(c,d,r,par);
                        ans--;
                    }
                }
            }
            // cout<<"pop";
            v.push_back(ans);
        }
        return v;
    }
};