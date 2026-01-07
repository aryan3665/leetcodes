class Solution {
public:
    long long sum = 0;
    long long maxp = 0;

    long long totalsum(TreeNode* root) {
        if (!root) return 0;
        return totalsum(root->left) + totalsum(root->right) + root->val;
    }

    long long find(TreeNode* root) {
        if (!root) return 0;

        long long leftsum = find(root->left);
        long long rightsum = find(root->right);

        long long s1 = leftsum + rightsum + root->val;
        long long s2 = sum - s1;

        maxp = max(maxp, s1 * s2);
        return s1;
    }

    int maxProduct(TreeNode* root) {
        sum = totalsum(root);
        find(root);
        return maxp % 1000000007;
    }
};
