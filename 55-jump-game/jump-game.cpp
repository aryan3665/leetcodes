class Solution {
public:
    int t[10001]; // -1 = unvisited, 0 = false, 1 = true
    
    bool solve(vector<int>& nums, int idx) {
        if (idx >= nums.size()) return false; // out of bounds
        if (idx == nums.size() - 1) return true; // reached last index
        
        if (t[idx] != -1) return t[idx]; // memo check

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (solve(nums, idx + jump)) {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
};
