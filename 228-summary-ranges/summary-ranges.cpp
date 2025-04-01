class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result; // Edge case: empty array

        int start = 0; // Start index of the current range

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) { // If numbers are not consecutive
                if (start == i - 1) 
                    result.push_back(to_string(nums[start])); // Single number
                else 
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1])); // Range
                
                start = i; // Start a new range
            }
        }

        // Handling the last range separately (including single-element cases)
        if (start == n - 1) {
            result.push_back(to_string(nums[start]));
        } else {
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[n - 1]));
        }

        return result;
    }
};
