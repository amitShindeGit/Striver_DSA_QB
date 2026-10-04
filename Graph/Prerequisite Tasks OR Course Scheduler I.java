class Solution {
    public boolean prerequisiteTasks(int n, int[][] pre) {
        // code here
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int m = pre.length;
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        
        
        for(int i=0; i<m; i++){
            adj.get(pre[i][1]).add(pre[i][0]);
        }
        
        // TOPO SORT BELOW
        int inDegree[] = new int[n];
        for(int i=0; i<n; i++){
            for(int it: adj.get(i)){
                inDegree[it]++;
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.add(i);
            }
        }
        
        List<Integer> topo = new ArrayList<>();
        while(!q.isEmpty()){
            int currentNode = q.poll();
            
            topo.add(currentNode);
            
            for(int it: adj.get(currentNode)){
                inDegree[it]--;
                if(inDegree[it] == 0) q.add(it);
            }
        }
        
        if(topo.size() == n) return true;
        return false;
    }
}