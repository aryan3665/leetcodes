/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int start,int end, int& idx){

        if(start>end)return NULL;


        TreeNode*root=new TreeNode(preorder[idx]);
        int pos=start;
        for(;pos<=end;pos++){
            if(inorder[pos]==root->val){
                break;
            }
        }
        idx++;
        root->left=fun(preorder,inorder,start,pos-1,idx);
        root->right=fun(preorder,inorder,pos+1,end,idx);

        return root;

    }
        
        TreeNode* buildTree(vector<int>& preorder,
                                                         vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0; // to traverse in preorder to make root;
        return fun(preorder, inorder, 0, n - 1,
                   idx); // 0 and n-1 are start and end index of inorder
    }
};