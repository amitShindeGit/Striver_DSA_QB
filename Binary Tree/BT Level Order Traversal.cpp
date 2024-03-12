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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode*, int>> q;

        q.push({root,root->val});
        ans.push_back({root->val});


        while(!q.empty()){
            TreeNode* currentNode = q.front().first;
            int currentSize = q.size();
            
            vector<int> tempVec;
            for(int i=0; i<currentSize; i++){
                currentNode = q.front().first;
                if(currentNode->left){
                    q.push({currentNode->left, currentNode->val});
                    tempVec.push_back(currentNode->left->val);
                }

                if(currentNode->right){
                    q.push({currentNode->right, currentNode->val});
                    tempVec.push_back(currentNode->right->val);
                }
                q.pop();

            }
            if(tempVec.size()){
            ans.push_back(tempVec);
            }
        }

    //     for (const auto& innerVec : ans) {
    //     // Print the first element of each inner vector
    //     std::cout << innerVec.front() << " ";
    // }

        
        return ans;
    }
};