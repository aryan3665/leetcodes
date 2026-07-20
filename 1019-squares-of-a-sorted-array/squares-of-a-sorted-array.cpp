class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());

        int i = 0;
        while (i < nums.size() && nums[i] < 0) {
            i++;
        }

        int j = i;
        i--;

        int k = 0;

        while (i >= 0 && j < nums.size()) {
            if (nums[i] * nums[i] <= nums[j] * nums[j]) {
                ans[k++] = nums[i] * nums[i];
                i--;
            } else {
                ans[k++] = nums[j] * nums[j];
                j++;
            }
        }

        while (i >= 0) {
            ans[k++] = nums[i] * nums[i];
            i--;
        }

        while (j < nums.size()) {
            ans[k++] = nums[j] * nums[j];
            j++;
        }

        return ans;
    }
};