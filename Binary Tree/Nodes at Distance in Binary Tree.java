/* Structure of Binary Tree Node
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int val) {
        data = val;
        left = null;
        right = null;
    }
};
*/
class Solution {
    private Node getTargetNode(Node root, int target){
        if(root == null){
            return null;
        }
        
        if(root.data == target){
            return root;
        }
        
        Node leftNode = getTargetNode(root.left, target);
        
        if(leftNode != null){
            return leftNode;
        }
        
        return getTargetNode(root.right, target);
    }
    
    private void markParents(Node root, Map<Node, Node> parent_track){
        Queue<Node> q = new LinkedList<Node>();
        
        q.offer(root);
        
        while(!q.isEmpty()){
            Node current = q.poll();
            
            if(current.left != null){
                parent_track.put(current.left, current);
                q.offer(current.left);
            }
            
            if(current.right != null){
                parent_track.put(current.right, current);
                q.offer(current.right);
            }
        }
    }
    
    public ArrayList<Integer> kDistanceNodes(Node root, int target, int k) {
        // code here
        Map<Node, Node> parent_track = new HashMap<>();
        Map<Node, Boolean> visited = new HashMap<>();
        Queue<Node> q = new LinkedList<Node>();
        
        // Get target node
        Node targetNode = getTargetNode(root, target);
        
        if (targetNode == null) {
            return new ArrayList<>();
        }
        
        // Get parent path track
        markParents(root, parent_track);
        
        q.offer(targetNode);
        visited.put(targetNode, true);
        int curr_lvl = 0;
        
        while(!q.isEmpty()){
            int size = q.size();
            if(curr_lvl == k) break;
            
            curr_lvl++;
            
            for(int i=0; i<size; i++){
                Node current = q.poll();
                if(current.left != null && visited.get(current.left) == null){
                    q.offer(current.left);
                    visited.put(current.left, true);
                }
                
                if(current.right != null && visited.get(current.right) == null){
                    q.offer(current.right);
                    visited.put(current.right, true);
                }
                
                if(parent_track.get(current) != null &&
                    visited.get(parent_track.get(current)) == null){
                    q.offer(parent_track.get(current));
                    visited.put(parent_track.get(current), true);
                }
            }
        }
        
        ArrayList<Integer> res = new ArrayList<Integer>();
        
        while(!q.isEmpty()){
            Node current = q.poll();
            res.add(current.data);
        }
        
        Collections.sort(res);
        
        return res;
        
    }
}