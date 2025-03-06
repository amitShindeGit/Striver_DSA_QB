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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode* currentRoot = root;
        while (currentRoot != NULL) {
            if (val > currentRoot->val) {
                if (currentRoot->right == NULL) {
                    currentRoot->right = new TreeNode(val);
                    return root;
                }
                currentRoot = currentRoot->right;
            } else {
                if (currentRoot->left == NULL) {
                    currentRoot->left = new TreeNode(val);
                    return root;
                }
                currentRoot = currentRoot->left;
            }
        }

        return root;
    }
};