/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
  int solve(Node*root,int curr){
      if(!root)return 0;
      curr= 10*curr+root->data;
  if(root->left==NULL&&root->right==NULL){
      return curr;
  }
  
  int l=solve(root->left,curr);
  int r=solve(root->right,curr);
  
  return l+r;
  }
    int treePathsSum(Node *root) {
        // code here.
     
         return solve(root,0);
    }
};