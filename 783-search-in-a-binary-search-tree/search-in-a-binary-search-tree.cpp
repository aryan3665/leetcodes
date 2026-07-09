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
TreeNode*search(TreeNode*root,int val){
if(!root)return NULL;
    if(root->val==val)return root;
    TreeNode*l=NULL;
    TreeNode*r=NULL;
    if(val<root->val){
        l=search(root->left,val);
    }
    else{
        r=search(root->right,val);
    }

    return (l!=NULL)?l:r; 
}
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode*ans=search(root,val);
        return ans;
    }
};