class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);  // new node create and return
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);   // go left
        } else {
            root->right = insertIntoBST(root->right, val); // go right
        }

        return root;
    }
};
