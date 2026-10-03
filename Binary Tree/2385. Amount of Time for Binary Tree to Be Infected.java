/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private TreeNode getTargetNode(TreeNode root, int start){
        if(root == null){
            return null;
        }

        if(root.val == start){
            return root;
        }

        TreeNode leftNode = getTargetNode(root.left, start);
        if(leftNode != null){
            return leftNode;
        }

        return getTargetNode(root.right, start);
    }

    private void getParentMapping(TreeNode root, Map<TreeNode, TreeNode> parent_track){
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        q.offer(root);

        while(!q.isEmpty()){
            TreeNode current = q.poll();

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

    public int amountOfTime(TreeNode root, int start) {
        Map<TreeNode, TreeNode> parent_track = new HashMap<TreeNode, TreeNode>();
        Map<TreeNode, Boolean> visited = new HashMap<>();

        getParentMapping(root, parent_track);
        TreeNode startNode = getTargetNode(root, start);
        if (startNode == null) {
            return 0;
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(startNode);
        visited.put(startNode, true);
        int mins = 0;

        while(!q.isEmpty()){
            int size = q.size();

            mins++;

            for(int i=0; i<size; i++){
                TreeNode current = q.poll();

                if(current.left != null && visited.get(current.left) == null){
                    q.offer(current.left);
                    visited.put(current.left, true);
                }

                if(current.right != null && visited.get(current.right) == null){
                    q.offer(current.right);
                    visited.put(current.right, true);
                }

                if(parent_track.get(current) != null
                    && visited.get(parent_track.get(current)) == null){
                        q.offer(parent_track.get(current));
                        visited.put(parent_track.get(current), true);
                }
            }
        }

        return mins-1;
    }
}