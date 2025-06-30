class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result=0;
       map<int,int>mp;
        int n=nums.size();
        for(auto&it:nums){
            mp[it]++;
        }
        for(int i=0;i<n;i++){
            int mini=nums[i];
            int maxi=mini+1;
            if(mp.count(maxi)){
             result=max(result,mp[mini]+mp[maxi]);
            }
        }
        return result;
       
    }
};