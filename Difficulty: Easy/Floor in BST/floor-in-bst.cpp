/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  int ans=INT_MIN;
  void f(Node*root,int k){
      if(!root)return;
      
      if(root->data<=k){
          ans=max(ans,root->data);
          f(root->right,k);
      }
      
      if(root->data>k){
          f(root->left,k);
      }
  }
  
    int findMaxFork(Node* root, int k) {
        // code here
        f(root,k);
        return (ans==INT_MIN ? -1:ans);
    }
};