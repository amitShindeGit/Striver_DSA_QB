class Solution {
private:
    void dfs(vector<vector<int>> adj, vector<int>& vis,int node) {
        // Code here
        vis[node] = 1;
        
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
        
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int isConnectedSize = isConnected.size();

        if(isConnectedSize == 0){
            return 0;
        }

        vector<vector<int> > adj(isConnectedSize);

        for(int i=0;i<isConnectedSize;i++){
            for(int j=0;j<isConnectedSize; j++){
                if(isConnected[i][j] && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(isConnectedSize,0);
        int ans = 0;
        for(int i=0; i<isConnectedSize;i++){
            if(!vis[i]){
                ans++;
                dfs(adj,vis,i);
            }
        }

        return ans;
    }
};