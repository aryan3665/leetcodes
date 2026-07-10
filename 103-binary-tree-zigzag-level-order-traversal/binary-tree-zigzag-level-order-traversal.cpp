class Solution {
public:
    void bfs(TreeNode* root, vector<vector<int>>& ans, bool ltor) {
        if (!root)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            vector<int> temp(n);

            int left = 0;
            int right = n - 1;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (ltor) {
                    temp[left++] = node->val;
                } else {
                    temp[right--] = node->val;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(temp);
            ltor = !ltor; // Flag flip kiya
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool ltor = true;
        vector<vector<int>> ans;
        bfs(root, ans, ltor);
        return ans;
    }
};