class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;

        // Edge case: empty tree
        if (root == nullptr)
            return ans;

        // Queue for level-order traversal
        queue<Node*> q;
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at current level
            vector<int> temp; // To store current level values

            // Process all nodes of the current level
            while(n--) {
                Node* fronty = q.front(); // Get the front node
                q.pop(); // Remove it from the queue

                temp.push_back(fronty->data); // Store its data

                // Push left child if exists
                if (fronty->left)
                    q.push(fronty->left);

                // Push right child if exists
                if (fronty->right)
                    q.push(fronty->right);
            }

         
            ans.push_back(temp);
        }

        return ans; 
    }
};
