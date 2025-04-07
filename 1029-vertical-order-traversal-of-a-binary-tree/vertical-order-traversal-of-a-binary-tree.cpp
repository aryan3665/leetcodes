/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store: vertical (x) → level (y) → multiset of node values
        // This helps in sorting nodes first by vertical, then by level,
        // and within same level, values are sorted due to multiset
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal: stores (node, (vertical, level))
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // Start with root at (x=0, y=0)

        // BFS traversal
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;  // vertical line
            int y = p.second.second; // level (depth)

            // Insert node value into corresponding position in map
            nodes[x][y].insert(node->val);

            // Add left child with vertical-1 and level+1
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }

            // Add right child with vertical+1 and level+1
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        // Prepare final answer from the map
        vector<vector<int>> ans;

        // Traverse map in order: left to right vertical lines
        for (auto p : nodes) {
            vector<int> col;

            // For each level in this vertical line
            for (auto q : p.second) {
                // Insert all node values (sorted due to multiset) into column
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            // Add the column to final result
            ans.push_back(col);
        }

        return ans;
    }
};
