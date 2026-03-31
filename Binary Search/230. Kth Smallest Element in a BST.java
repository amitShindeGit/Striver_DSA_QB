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
    private int ans = 0;
    private int count = 0;
    private void inOrderTraversal(TreeNode root, int k) {

        if (root == null)
            return;

        inOrderTraversal(root.left, k);
        count++;

        if (count == k){
            ans = root.val;
            return;
        }

        inOrderTraversal(root.right, k);
    }

    public int kthSmallest(TreeNode root, int k) {

        inOrderTraversal(root, k);

        return ans;
    }
}