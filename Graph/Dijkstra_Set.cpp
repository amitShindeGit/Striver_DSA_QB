class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        st.insert({0, src});
        
        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if (dis + edgeWeight < dist[adjNode]) {
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
