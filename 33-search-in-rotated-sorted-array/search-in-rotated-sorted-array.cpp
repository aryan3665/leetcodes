class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        int n = nums.size();

       
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i; 
        }

        
        if (mp.find(target) != mp.end()) {
            return mp[target];  // Return the stored index
        }

        return -1;  // Target not found
    }
};
