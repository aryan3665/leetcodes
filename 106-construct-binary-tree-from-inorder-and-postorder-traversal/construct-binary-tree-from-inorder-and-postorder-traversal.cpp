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

    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int index) {
        if (instart > inend) {
            return NULL; // Base case
        }

       
       

        TreeNode* root = new TreeNode(postorder[index]);
        int pos = find(inorder, postorder[index], instart, inend);

        // Check if position is valid
        if (pos == -1) {
            // Handle error: target not found in inorder
            return NULL; // or throw an exception
        }

               root->right = tree(inorder, postorder, pos + 1, inend, index-1);

        root->left = tree(inorder, postorder, instart, pos - 1, index -(inend-pos)-1);
 

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty()) {
            return NULL; // Return NULL for empty input
        }
        
        int n = postorder.size();
        return tree(inorder, postorder, 0, n - 1, n-1);
    }
};