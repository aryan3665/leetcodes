/* A binary tree Node

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(Node *root) {
        // code her
        vector<vector<int>>ans;
        vector<int>trr;
        queue<Node*>q;
        q.push(root);
        Node*temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            trr.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        ans.push_back(trr);
        return ans;
    }
};
