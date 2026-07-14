class Solution {
public:
    void solve(TreeNode* root, int target, vector<int>& path,
               vector<vector<int>>& ans) {
        if (root == NULL)
            return;

        path.push_back(root->val);

        // Leaf
        if (root->left == NULL && root->right == NULL) {
            if (target == root->val)
                ans.push_back(path);

            path.pop_back();
            return;
        }

        target -= root->val;

        solve(root->left, target, path, ans);

        solve(root->right, target, path, ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, path, ans);

        return ans;
    }
};
