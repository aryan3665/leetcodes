class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute force to simple hai bus map banake freq count kara hai o(n) space complexity me hoga


        //moore algo
        int n=nums.size();
        int count=1;
        int candidate=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=candidate)count--;
            if(nums[i]==candidate)count++;
             if(count==0){
                candidate=nums[i];
                count=1;
            }
        }
        return candidate;
    }
};