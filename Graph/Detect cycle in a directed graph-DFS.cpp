//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detectCycle(int src,vector<int> adj[], int visited[], int dfsVisited[] ){
            visited[src] = 1;
            dfsVisited[src] = 1;

                for(auto adjancentNode : adj[src]){
                    if(!visited[adjancentNode]){
                        if(detectCycle(adjancentNode, adj,visited, dfsVisited)) return true;
                    }else if(dfsVisited[adjancentNode]){
                        return true;
                    }
                }
                
                dfsVisited[src] = 0;
                return false;
            
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int dfsVisited[V] = {0};
        

        for(int i=0; i<V; i++){
            if(!visited[i] ){
                if(detectCycle(i,adj, visited, dfsVisited)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends