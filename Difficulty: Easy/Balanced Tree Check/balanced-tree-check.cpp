/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
  int height(Node*root){
      if(!root)return 0;
      
      return 1+max(height(root->left),height(root->right));
  }
    bool isBalanced(Node* root) {
        // Code here
        
        if(!root)return 1;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(rh-lh)>1)return 0;
        
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};