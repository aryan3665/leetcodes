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
    vector<int> bottomView(Node *root) {
        // Your Code Here
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
            
          
                mp[vline] = node->data;
            
            
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