class Solution {
public:
    int solve(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (root->val < low) {
            return solve(root->right, low, high);
        }
        if (root->val > high) {
            return solve(root->left, low, high);
        }
        return root->val + solve(root->left, low, high) + solve(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};
