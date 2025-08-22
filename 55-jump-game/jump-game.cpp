class Solution {
public:
    int t[10001]; // -1 = unvisited, 0 = false, 1 = true

    bool solve(vector<int>& nums, int idx) {
        if (idx >= nums.size())
            return false; // out of bounds
        if (idx == nums.size() - 1)
            return true; // reached last index

        if (t[idx] != -1)
            return t[idx]; // memo check

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (solve(nums, idx + jump)) {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); // 0 = false, 1 = true
        dp[0]=1;
        //dp[i]=1 we can reach there at i else cannot
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]==1&&j+nums[j]>=i){
                    dp[i]=1;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};
