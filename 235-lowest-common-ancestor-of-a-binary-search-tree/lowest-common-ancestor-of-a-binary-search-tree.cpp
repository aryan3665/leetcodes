/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode*s(TreeNode* root,int n1,int n2){
if(!root)return NULL;


    if(root->val>n1&&root->val>n2){
        return s(root->left,n1,n2);
    }
    else if(root->val<n1&&root->val<n2){
        return s(root->right,n1,n2);
    }
    else{
        return root;
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1=p->val;
        int n2=q->val;

       return s(root,n1,n2);
    }
};