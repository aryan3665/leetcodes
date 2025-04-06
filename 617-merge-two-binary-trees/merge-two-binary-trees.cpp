class Solution {
public:
    TreeNode* solve(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        
        int val = 0;
        TreeNode* left1 = nullptr;
        TreeNode* right1 = nullptr;
        TreeNode* left2 = nullptr;
        TreeNode* right2 = nullptr;
        
        if (root1) {
            val += root1->val;
            left1 = root1->left;
            right1 = root1->right;
        }
        if (root2) {
            val += root2->val;
            left2 = root2->left;
            right2 = root2->right;
        }

        TreeNode* node = new TreeNode(val);
        node->left = solve(left1, left2);
        node->right = solve(right1, right2);

        return node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
