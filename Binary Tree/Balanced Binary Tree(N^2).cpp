/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getDepthOfNode (TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int leftDepth = 1 + getDepthOfNode(root->left);
        int rightDepth = 1 + getDepthOfNode(root->right);

        return max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int depthOfLeft = getDepthOfNode(root->left);
        int depthOfRight = getDepthOfNode(root->right);

        if(abs(depthOfLeft - depthOfRight) > 1){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};