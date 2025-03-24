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
TreeNode*bst(vector<int>&pre,int &index,int lower,int upper){

if(index==pre.size()||pre[index]<lower||pre[index]>upper){
    return NULL;
}


    TreeNode*root=new TreeNode(pre[index++]);
    root->left=bst(pre,index,lower,root->val);
    root->right=bst(pre,index,root->val,upper);

    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return bst(preorder,index,INT_MIN,INT_MAX);
    }
};