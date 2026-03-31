/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p.val > root.val && q.val > root.val){
            // First case -> If both are on the right then iterate right side of root
            return lowestCommonAncestor(root.right,p, q);
        }else if(p.val < root.val && q.val < root.val){
            // Second case -> If both are on the left side, then iterate left side of root
            return lowestCommonAncestor(root.left, p, q);
        }else{
            // If both are on either side of the root, then the root itself is the LCA
            return root;
        }
    }
}