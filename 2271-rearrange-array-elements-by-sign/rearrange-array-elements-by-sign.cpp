class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0;
        int j = 1;
        int ind = 0;
        for (int ind = 0; ind < n; ind++) {
            if (nums[ind] >= 0) {
                result[i] = nums[ind];
                if (i + 2 < n) {
                    i += 2;
                }

            } else if (nums[ind] < 0) {
                result[j] = nums[ind];
                if (j + 2 < n) {
                    j += 2;
                }
            }
        }
        return result;
    }
};