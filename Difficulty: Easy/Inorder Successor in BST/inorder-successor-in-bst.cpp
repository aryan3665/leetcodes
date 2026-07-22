/*
Definition for Node
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
   void solve(Node* root, int x, int &ans) {  // pass by reference
      if (!root) return;

      if (root->data >x) {
          ans = root->data;              // potential ceil
          solve(root->left, x, ans);     // left me aur chhoti value check karo
      } else {
          solve(root->right, x, ans);    // right side me badi value check karo
      }
  }

    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        int ans = -1;
        int x=k->data;
      solve(root, x, ans);
      return ans;
    }
};