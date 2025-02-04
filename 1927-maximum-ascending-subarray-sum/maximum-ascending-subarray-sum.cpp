class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], sum = nums[0]; // Start from first element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i]; // Continue ascending subarray
            } else {
                ans = max(ans, sum); // Update max sum
                sum = nums[i]; // Start new subarray
            }
        }
        return max(ans, sum); // Final update
    }
};
