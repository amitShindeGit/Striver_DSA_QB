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
    int getMaxDepth(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        int left = 1 + getMaxDepth(node->left);
        int right = 1 + getMaxDepth(node->right);

        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        int ans = getMaxDepth(root);

        return ans;
    }
};