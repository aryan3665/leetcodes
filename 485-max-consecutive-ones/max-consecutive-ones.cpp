class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
               
                c=0;
            }
            else{
                c++;
                 maxi=max(maxi,c);
            }
        }
        return maxi;
    }
};