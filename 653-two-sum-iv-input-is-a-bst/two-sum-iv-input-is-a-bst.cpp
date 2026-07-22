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
    stack<TreeNode*>asc;
    stack<TreeNode*>desc;
     int getsmall() {
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightchild = small->right;
        while (rightchild != NULL) {
            asc.push(rightchild);
            rightchild = rightchild->left;
        }
        return small->val;
    }

    int getbig() {
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* leftchild = big->left;
        while (leftchild != NULL) {
            desc.push(leftchild);
            leftchild = leftchild->right;
        }
        return big->val;
    }
    bool findTarget(TreeNode* root, int k) {
     TreeNode* t = root;
        while (t) {
            asc.push(t);
            t = t->left;
        }
        t = root;
        while (t) {
            desc.push(t);
            t = t->right;
        }
        int s = getsmall(), e = getbig();
        while (s < e) {
            if (s + e == k)
                return true;
            else if (s + e < k)
                s = getsmall();
            else
                e = getbig();
        }
        return false;

    }
};