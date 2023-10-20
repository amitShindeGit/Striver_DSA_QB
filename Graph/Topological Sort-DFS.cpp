#include <bits/stdc++.h> 

void dfsTopoSort(int node,int visited[],vector<vector<int>> &adj, stack<int> &q){
        visited[node] = 1;
        
        for(auto adjacentNode: adj[node]){
            if(!visited[adjacentNode]){
                dfsTopoSort(adjacentNode, visited,adj,q);
            }
        }
        q.push(node);
    }


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);

    for(int i=0; i<e; i++){

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

    }

     int visited[v]= {0};
	    stack<int> q;
	    vector<int> ans;
	    
	    for(int i=0; i<v;i++){
	    if(!visited[i]){
	        dfsTopoSort(i,visited,adj,q);
	    }
	    }
	    
	    while (!q.empty()) {
       
        ans.push_back(q.top());
        q.pop();
    }
	    
	    return ans;
}