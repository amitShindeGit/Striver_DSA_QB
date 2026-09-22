/* Node Structure
class Node{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
} */
class Solution {
    private boolean checkSumProperty(Node root){
        if(root == null || (root.left == null && root.right == null)){
            return true;
        }
        
        int left = root.left != null ? root.left.data : 0;
        int right = root.right != null ? root.right.data : 0;
        
        if((left + right == root.data) && 
            checkSumProperty(root.left) &&
            checkSumProperty(root.right)){
            return true;
        }else{
            return false;
        }
        
    }
    
    public boolean isSumProperty(Node root) {
        //  code here
        if(root == null) return true;
        
        return checkSumProperty(root);
    }
}