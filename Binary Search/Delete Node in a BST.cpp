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
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRightChild = findLastRightNode(root->left);
        lastRightChild->right = rightChild;
        return root->left;

    }

    TreeNode* findLastRightNode (TreeNode* root){
        if(root->right == NULL){
            return root;
        }

        return findLastRightNode(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }

        if(root->left == NULL && root->right == NULL && root->val == key){
            root = NULL;
            return root;
        }

        if(root->val == key){
            return helper(root);
        }

        

        //search Node
        TreeNode* copyOfRoot = root;
        TreeNode* requiredNode = NULL;
        while(copyOfRoot != NULL){
            if(copyOfRoot->left != NULL && key == copyOfRoot->left->val){
                requiredNode = copyOfRoot;
                break;
            }else if(copyOfRoot->right != NULL && key == copyOfRoot->right->val){
                requiredNode = copyOfRoot;
                break;
            }

            if(key > copyOfRoot->val){
                copyOfRoot = copyOfRoot->right;
            }else{
                copyOfRoot = copyOfRoot->left;
            }
        }
        
        
        if(requiredNode != NULL){
            //Left case
          if(key < requiredNode->val ){
            copyOfRoot->left = helper(copyOfRoot->left);
          }else{
            copyOfRoot->right = helper(copyOfRoot->right);
          }
        }else{
            //Key is not found
            return root;
        }
        return root;
    }
};