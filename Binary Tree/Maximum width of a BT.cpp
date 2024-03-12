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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
                return 0;
            }

        queue<pair<TreeNode *, int>> q;
        int ans = 0;

        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            int currentMinIndex = q.front().second;
            int first, last;
            for(int i=0; i<size;i++){
                int currentIndex = q.front().second - currentMinIndex;
                TreeNode *currNode = q.front().first;
                q.pop();

                if(i == 0){
                    first = currentIndex;
                }
                 if(i == size-1){
                    last = currentIndex;
                }

                if(currNode->left){
                    q.push({currNode->left, 2 * (long long)currentIndex + 1});
                }
                 if(currNode->right){
                    q.push({currNode->right, 2 * (long long)currentIndex + 2});
                }
            }

            ans = max(ans, last - first + 1 );
        }

        return ans;
    }
};