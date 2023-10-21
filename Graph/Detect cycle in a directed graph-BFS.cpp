//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int> Q;
        int count = 0;
        vector<int> inDegree(V,0);
        
        for(int i=0; i< V; i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        
        for(int i=0; i< inDegree.size(); i++){
            if(inDegree[i] == 0){
                Q.push(i);
            }
        }
        
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            count++;
            
            for(auto it : adj[node]){
                inDegree[it] -= 1;
                
                if(inDegree[it] == 0){
                    Q.push(it);
                }
            }
        }
        
        if(count == V){
            //Means Topological sort works which means it is a DAG, hence not cyclic
            return false;
        }
        
        return true;
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