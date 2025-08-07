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
    vector<int> largestValues(TreeNode* root) {
          vector<int>ans;
          queue<TreeNode * >q;
          if(root==NULL) return ans;
          q.push(root);
          while(!q.empty()){
            int s=q.size();
            int m=INT_MIN;
            while(s--){
                TreeNode* prev=q.front();
                q.pop();
                m=max(prev->val,m);
                if(prev->left)
                q.push(prev->left);
                if(prev->right)
                q.push(prev->right);

            }
            ans.push_back(m);
          }
    return ans;   
    }
};