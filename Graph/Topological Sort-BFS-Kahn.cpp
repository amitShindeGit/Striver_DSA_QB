#include <bits/stdc++.h> 
#include <iostream>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    vector<int> ans;
    vector<int> indegree(v, 0);
    queue<int> q;
 
     for(int i=0; i<e; i++){

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

    }

    for(int i=0; i<v; i++){
     for(auto it: adj[i]){
        indegree[it]++;
        }
    }

    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int qTop = q.front();
        ans.push_back(q.front());
        q.pop();

        for(auto it: adj[qTop]){
            indegree[it] -= 1;

            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }


    return ans;
}