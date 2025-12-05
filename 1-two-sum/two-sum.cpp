class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;  
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int search = target - nums[i];

            if (mp.find(search) != mp.end()) {
                ans.push_back(mp[search]);
                ans.push_back(i);
                return ans;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};
