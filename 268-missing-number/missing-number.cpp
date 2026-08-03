class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // brute force
        int n = nums.size();
        int i = 0;
        bool f = 0;
        while (i <= n) {
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    f = 1;
                    break;
                }
            }

            if (f == 0)
                return i;
            i++;
            f=0;
        }

        return -1;
    }
};