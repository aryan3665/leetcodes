/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  bool s(Node*root,long long &prev){
      if(!root)return 1;
      
      
      if(!s(root->left,prev))return false;
      if(root->data<prev)return false;
      prev=root->data;
      return s(root->right,prev);
  }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        long long prev=INT_MIN;
        return s(root,prev);
        
    }
};