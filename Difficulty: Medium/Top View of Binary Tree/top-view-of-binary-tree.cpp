/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        
        map<int, int> mp; // vertical -> node->data
        queue<pair<Node*, int>> q; // node, vertical
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int vline = temp.second;
            
            // only insert if vertical line not already filled
            if (mp.find(vline) == mp.end()) {
                mp[vline] = node->data;
            }
            
            if (node->left) {
                q.push({node->left, vline - 1});
            }
            if (node->right) {
                q.push({node->right, vline + 1});
            }
        }
        
        // store map values in ans
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
