class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // If the number is greater than target, break (since sorted)
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, temp, ans);
            temp.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());  // sort to handle duplicates
        backtrack(candidates, target, 0, temp, ans);
        return ans;
    }
};
