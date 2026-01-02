class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        //by observation jo repetede element hai uska index gar i hai to aisa ek condition jarur hoga jisme i-1 ya i-2 index pe same value hogi 
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]||((i!=1)&&(nums[i]==nums[i-2]))){
                return nums[i];
            }
            if(nums[n-1]==nums[0])return nums[0];
        }
        return -1;
    }
};