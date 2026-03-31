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

import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q = new ArrayDeque<>();
        boolean leftToRight = true;

        if(root == null) return ans;

        q.offer(root);

        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> subAns = new ArrayList<>();
            for(int i=0; i<size; i++){
                TreeNode currentNode = q.poll();

                // ArrayList to insert values from back, keep index fix at 0
                subAns.add(leftToRight ? i : 0, currentNode.val);

                if(currentNode.left != null){
                    q.offer(currentNode.left);
                }

                if(currentNode.right != null){
                    q.offer(currentNode.right);
                }
            }
            leftToRight = !leftToRight;
            ans.add(subAns);
        }

        return ans;


    }
}