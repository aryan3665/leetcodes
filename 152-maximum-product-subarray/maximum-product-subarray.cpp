class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=minp*nums[i];
            int v3=maxp*nums[i];
            minp=min({v1,v2,v3});
            maxp=max({v1,v2,v3});
            ans=max(ans,max(minp,maxp));
        }

        return ans;
    }
};