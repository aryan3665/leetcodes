class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int> maxt(n);
        vector<int> minit(n);
        // maxt[0] = nums[0];
        // for (int i = 1; i < n; i++) {
        //     maxt[i] = max(maxt[i - 1], nums[i]);
        // }
        minit[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minit[i] = min(minit[i + 1], nums[i]);
        }
        int ans = -1;
        int maxt=nums[0];

        for (int i = 0; i < n; i++) {
            maxt=max(maxt,nums[i]);
            if ((maxt - minit[i]) <= k) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};