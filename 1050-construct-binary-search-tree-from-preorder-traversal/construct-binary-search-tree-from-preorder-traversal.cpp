/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* s(vector<int>& preorder, int& index, int l, int u) {
        if (index == preorder.size() || preorder[index] < l || preorder[index] > u)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = s(preorder, index, l, root->val);
        root->right = s(preorder, index, root->val, u);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return s(preorder, index, INT_MIN, INT_MAX);
    }
};
