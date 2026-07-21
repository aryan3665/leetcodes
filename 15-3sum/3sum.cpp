class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int h = n - 1;
            int target = -nums[i];

            while (l < h) {

                int sum = nums[l] + nums[h];

                if (sum == target) {

                    ans.push_back({nums[i], nums[l], nums[h]});

                    // Skip duplicates
                    while (l < h && nums[l] == nums[l + 1])
                        l++;

                    while (l < h && nums[h] == nums[h - 1])
                        h--;

                    l++;
                    h--;
                }
                else if (sum < target) {
                    l++;
                }
                else {
                    h--;
                }
            }
        }

        return ans;
    }
};