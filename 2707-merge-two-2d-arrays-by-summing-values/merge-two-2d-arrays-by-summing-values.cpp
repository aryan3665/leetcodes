class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        int n=nums1.size();
         for (auto num : nums1) mp[num[0]] = num[1];
        for (auto num : nums2) mp[num[0]] += num[1];

         vector<vector<int>> res;
        for (auto [key, val] : mp) res.push_back({key, val}); // in a map keys are always sorted
        return res;
        
    }
};