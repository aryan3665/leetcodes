class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maxi=max(maxi,cur);
                cur=0;
            }
            else{
                cur++;
            }

            maxi=max(maxi,cur);
        }
        return maxi;
    }
};