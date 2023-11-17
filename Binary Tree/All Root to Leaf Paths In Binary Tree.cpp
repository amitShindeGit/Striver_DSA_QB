/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/

void getRootToLeaf(BinaryTreeNode<int> * root, vector <string> &ans,string s) {
   if(root == NULL){
       return;
   } 

  if (root->left == NULL && root->right == NULL) {
      s += to_string(root->data);
      ans.push_back(s);
      return;
  } 

  s += to_string(root->data) + " ";

  getRootToLeaf(root->left, ans, s);
  getRootToLeaf(root->right,ans, s);

}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector <string> ans;

    if (root == NULL) {
        return ans;
    }   

    getRootToLeaf(root, ans, "");

    return ans;
    
}