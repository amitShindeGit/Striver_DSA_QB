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
    int getDiameter(TreeNode* node, int& diameter){
        if(node == NULL){
            return 0;
        }

        int lh = getDiameter(node->left,diameter);
        int rh = getDiameter(node->right,diameter);

        diameter = max(diameter, lh+rh);
        return 1 + max(lh,rh);

    }


    int diameterOfBinaryTree(TreeNode* root) {
       int diameter = 0;

       getDiameter(root, diameter);

       return diameter;
    }
};