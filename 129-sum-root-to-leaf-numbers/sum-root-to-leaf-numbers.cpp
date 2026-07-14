class Solution {
public:
    int global_sum = 0;

    void f(TreeNode* root, int num) {
        if (!root) return;

        num = num * 10 + root->val;

        if (!root->left && !root->right) {
            global_sum += num;
            return;
        }

        f(root->left, num);
        f(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        f(root, 0);
        return global_sum;
    }
};