/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getMaxPathSum(TreeNode* node, int& maxValue) {
        if (node == NULL) {
            return 0;
        }

        int leftSum = max(0,getMaxPathSum(node->left, maxValue)); //don't consider negatives
        int rightSum = max(0,getMaxPathSum(node->right, maxValue)); //don't consider negatives

        maxValue = max(maxValue, leftSum + rightSum + node->val);

        return (node->val + max(leftSum, rightSum));
    }

    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxValue = INT_MIN;
        getMaxPathSum(root, maxValue);

        return maxValue;
    }
};