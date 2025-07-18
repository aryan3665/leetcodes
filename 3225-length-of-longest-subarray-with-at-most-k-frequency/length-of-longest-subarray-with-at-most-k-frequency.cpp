class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        map<int,int>mp;
        int result=INT_MIN;
        while(j<n){
            mp[nums[j]]++;
            while(i<j&&mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
          
                result=max(result,j-i+1);
                j++;
            
            
        }
        return result;
    }
};