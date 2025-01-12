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
    int find(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1; // Target not found
    }

    TreeNode* tree(vector<int>& inorder, vector<int>& preorder, int instart, int inend, int index) {
        if (instart > inend) {
            return NULL; // Base case
        }

        // Check if index is valid
        if (index < 0 || index >= preorder.size()) {
            return NULL; // Handle out-of-bounds access
        }

        TreeNode* root = new TreeNode(preorder[index]);
        int pos = find(inorder, preorder[index], instart, inend);

        // Check if position is valid
        if (pos == -1) {
            // Handle error: target not found in inorder
            return NULL; // or throw an exception
        }

        root->left = tree(inorder, preorder, instart, pos - 1, index + 1);
        root->right = tree(inorder, preorder, pos + 1, inend, index + (pos - instart + 1));

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Check if the input vectors are empty
        if (preorder.empty() || inorder.empty()) {
            return NULL; // Return NULL for empty input
        }
        
        int n = preorder.size();
        return tree(inorder, preorder, 0, n - 1, 0);
    }
};