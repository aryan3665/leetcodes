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
    int height(TreeNode* root , int &diameter){ 
        /*here we use int &diameter becuase updates to diameter are lost
         after returning from the recursion. We need to pass diameter
         by reference so that all recursive calls share the same variable*/
        if(root == NULL) return 0;
        int leftheight = height(root->left,diameter);
        int rightheight = height(root->right,diameter);
        diameter = max(diameter , (leftheight + rightheight));
        return 1 + max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};