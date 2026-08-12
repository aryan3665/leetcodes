class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i =0;
        int j=0;
        int maxi=INT_MIN;
        unordered_map<int,int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;

            //galat hone ki condition
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};