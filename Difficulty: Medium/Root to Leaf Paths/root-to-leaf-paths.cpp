/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void f(Node* root, vector<int>& temp, vector<vector<int>>& ans) {
        if (!root) return;

        // include current node
        temp.push_back(root->data);

        // if leaf, store the current path
        if (!root->left && !root->right) {
            ans.push_back(temp);
        } else {
            // recurse
            f(root->left, temp, ans);
            f(root->right, temp, ans);
        }

        // backtrack
        temp.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(root, temp, ans);
        return ans;
    }
};
