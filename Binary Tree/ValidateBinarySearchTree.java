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
    private boolean getIsValidBST(TreeNode root, long minVal, long maxVal){
        if(root == null) return true;

        if(root.val <= minVal || root.val >= maxVal) return false;

        return getIsValidBST(root.left, minVal, root.val) 
               && getIsValidBST(root.right, root.val, maxVal); 
    }

    public boolean isValidBST(TreeNode root) {
        
        boolean ans = getIsValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);

        return ans;
    }
}