class Solution {
private:
    bool dfsCheck(int start, vector<vector<int>>& graph, vector<int> vec,
                  int currentMark) {
        vec[start] = currentMark;

        for (auto it : graph[start]) {
            cout << it << " " << currentMark << endl;
            if (vec[it] == -1) {
                return dfsCheck(it, graph, vec, !currentMark);
            } else if (vec[it] == currentMark) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vec(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (vec[i] == -1) {
                if (dfsCheck(i, graph, vec, 0) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};