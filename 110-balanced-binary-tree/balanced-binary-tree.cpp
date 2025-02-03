class Solution {
public:
    int height(TreeNode* root, bool &valid) {
        if (!root) {
            return 0;
        }

        int l = height(root->left, valid);
        int r = height(root->right, valid); // Fix: Correct function call

        if (abs(l - r) > 1)
            valid = false;

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        bool valid = true;
        height(root, valid);
        return valid;
    }
};
