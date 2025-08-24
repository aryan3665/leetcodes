class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> ans;
        int count = 0;

        // Step 1: Break array into blocks of 1's separated by 0's
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                ans.push_back(count);
                count = 0;
            }
        }
        ans.push_back(count); // push last segment of 1's

        // Step 2: compute max by merging two consecutive segments
        int maxsum = 0;
        for (int i = 1; i < ans.size(); i++) {
            maxsum = max(maxsum, ans[i] + ans[i - 1]);
        }

        // Step 3: handle edge case where array is all 1's
        if (maxsum == 0) maxsum = *max_element(ans.begin(), ans.end());
        if (maxsum == nums.size()) maxsum--; 

        return maxsum;
    }
};
