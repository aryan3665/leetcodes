/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
  void inorder(vector<int>&ino,Node*root){
      if(!root)return ;
      
      inorder(ino,root->left);
      ino.push_back(root->data);
      inorder(ino,root->right);
  }
    int absDiff(Node *root) {
        // code here
        //brute force find inorder 
        vector<int>ino;
        inorder(ino,root);
        int mini=INT_MAX;
        for(int i=0;i<ino.size()-1;i++){
            mini=min(mini,abs(ino[i]-ino[i+1]));
        }
        return mini;
    }
};