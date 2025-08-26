/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};  // ✅ null check

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            while (n--) {
                TreeNode* c = q.front();
                q.pop();
                temp.push_back(c->val);

                if (c->left) q.push(c->left);
                if (c->right) q.push(c->right);
            }

            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());  // ✅ reverse for bottom-up
        return ans;
    }
};
