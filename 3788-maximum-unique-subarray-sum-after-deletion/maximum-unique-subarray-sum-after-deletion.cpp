class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, bool> seen;
        int total = 0;
        bool flag = false;

        for (int num : nums) {
            if (seen[num]) continue;
            seen[num] = true;
            if (num > 0) {
                flag = true;
                total += num;
            }
        }

        if (!flag) {
            return *max_element(nums.begin(), nums.end());
        }

        return total;
    }
};