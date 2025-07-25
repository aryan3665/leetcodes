// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int>maxi;

       

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

         
           int m= *max_element(temp.begin(),temp.end());
            maxi.push_back(m);
        }

        return maxi; 
    }
};