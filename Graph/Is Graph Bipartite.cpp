class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& vec) {
        queue<int> q;

        q.push(start);
        vec[start] = 0;

        while (!q.empty()) {
            int node = q.front();

            q.pop();

            for (auto it : graph[node]) {
                if (vec[it] == -1) {
                    vec[it] = !vec[node];
                    q.push(it);
                } else if (vec[it] == vec[node]) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty()) {
            return false;
        }

        vector<int> vec(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (vec[i] == -1) {
                if (check(i, graph, vec) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};