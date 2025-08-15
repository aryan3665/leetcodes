class Solution {
  public:
  
  bool isLeaf(Node* root) {
      return (!root->left && !root->right);
  }
  
  void addLeft(Node* root, vector<int>& res) {
      Node* curr = root->left;
      while(curr) {
          if(!isLeaf(curr)) res.push_back(curr->data);
          if(curr->left) curr = curr->left;
          else curr = curr->right;
      }
  }
  
  void addLeaves(Node* root, vector<int>& res) {
      if(isLeaf(root)) {
          res.push_back(root->data);
          return;
      }
      if(root->left) addLeaves(root->left, res);
      if(root->right) addLeaves(root->right, res);
  }
  
  void addRight(Node* root, vector<int>& res) {
      Node* curr = root->right;
      stack<int> st;
      while(curr) {
          if(!isLeaf(curr)) st.push(curr->data);
          
          if(curr->right) curr = curr->right;
          else curr = curr->left;
      }
      
      while(!st.empty()) {
          res.push_back(st.top());
          st.pop();
      }
  }
  
  vector<int> boundaryTraversal(Node *root) {
      vector<int> res;
      if(!root) return res;
      
      if(!isLeaf(root)) res.push_back(root->data);
      
      addLeft(root, res);
      addLeaves(root, res);
      addRight(root, res);
      
      return res;
  }
};
