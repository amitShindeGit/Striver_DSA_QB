//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    void getDfs(int visited[], vector<int> &dfs,  vector<int> adj[], int node){
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs.push_back(it);
                visited[it] = 1;
                getDfs(visited,dfs, adj, it);
            }
        }
    }

  
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfs;
        
        int visited[V] = {0};
        visited[0] = 1;
        
        int node = 0;
        dfs.push_back(0);
    
        getDfs(visited, dfs, adj, node);
        
        return dfs;
        
    }
};

//{ Driver Code Starts.
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends