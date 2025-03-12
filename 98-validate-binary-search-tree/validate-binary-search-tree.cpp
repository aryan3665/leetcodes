class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return isSorted(ans);
    }

private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool isSorted(vector<int>& ans) {
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1]) return false;  // Strictly increasing condition
        }
        return true;
    }
};
