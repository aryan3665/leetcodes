class Solution {
public:
    bool solve(TreeNode* root, long long &prev) {
        if (!root) return true;

        if (!solve(root->left, prev)) return false;

        if (root->val <= prev) return false;
        prev = root->val;

        return solve(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN; // use long long to handle INT_MIN case
        return solve(root, prev);
    }
};
