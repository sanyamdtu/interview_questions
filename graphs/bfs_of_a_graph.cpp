// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<int> g[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> res = bfs(adj, N);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends

/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector<int> bfs(vector<int> g[], int n)
{

    queue<int> q;
    q.push(0);
    int vis[n];
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    vector<int> ans;
    while (!q.empty())
    {
        int a = q.front();
        ans.push_back(a);
        q.pop();
        for (auto i : g[a])
        {
            if (vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return ans;
}