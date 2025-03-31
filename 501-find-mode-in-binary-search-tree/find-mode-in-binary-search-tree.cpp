class Solution {
public:
    void traverse(TreeNode* root, unordered_map<int, int>& freq) {
        if (!root) return;
        freq[root->val]++;
        traverse(root->left, freq);
        traverse(root->right, freq);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        traverse(root, freq);

        int maxFreq = 0;
        for (auto it : freq) {
            maxFreq = max(maxFreq, it.second);
        }

        vector<int> ans;
        for (auto it : freq) {
            if (it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
