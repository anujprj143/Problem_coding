
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool cyclicBFS(int V, int src, vector<int>vis, vector<int>g[]){
        vector<int>parent(V,0);
        queue<int>q;
        q.push(src);
        vis[src]=1;
        parent[src]=-1;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto x:g[curr]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                    parent[x]=curr;
                }else if(x!=parent[curr])
                    return true;
            }
            
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(cyclicBFS(V, i,visited,adj)){
                    return true;
                }
            }
            
        }
        return false;
        
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} 
