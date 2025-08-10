class Solution {
    private boolean dfsCheck(int node, int[][] adj, int[] vis, int[] pathVis, List<Integer> check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check.set(node, 0);

        for (int it : adj[node]) {
            if (vis[it] == 0) {
                if (dfsCheck(it, adj, vis, pathVis, check)) {
                    check.set(it, 0);
                    return true;
                }
            } else if (pathVis[it] == 1) {
                check.set(it, 0);
                return true;
            }
        }

        pathVis[node] = 0;
        check.set(node, 1);
        return false;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] vis = new int[n];
        int[] pathVis = new int[n];
        List<Integer> check = new ArrayList<>(Collections.nCopies(n, 0));
        List<Integer> safeNodes = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < n; i++) {
            if (check.get(i) == 1) {
                safeNodes.add(i);
            }
        }

        return safeNodes;
    }
}