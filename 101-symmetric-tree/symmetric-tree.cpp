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
  bool isMirror(TreeNode* a, TreeNode* b) {
        // base cases
        if (a == NULL && b == NULL) return true;   // both null → symmetric
        if (a == NULL || b == NULL) return false;  // one null only → not symmetric
        if (a->val != b->val) return false;      // values differ → not symmetric

        // check mirror condition: outside with outside, inside with inside
        return isMirror(a->left, b->right) && 
               isMirror(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // empty tree is symmetric
        return isMirror(root->left, root->right);  
    }
};