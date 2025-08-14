class Solution {
public:
    int solve(TreeNode* root, int &sum) {
        if(!root) return 0;
        
        int left = max(0, solve(root->left, sum));
        int right = max(0, solve(root->right, sum));
        
        sum = max(sum, root->val + left + right);
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root, sum);
        return sum;
    }
};