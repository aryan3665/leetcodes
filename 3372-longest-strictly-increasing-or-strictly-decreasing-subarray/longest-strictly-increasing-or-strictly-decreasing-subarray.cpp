class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int in=1;
        int d=1;
        int l=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                in++;

            }
            else{
                in=1;
            }

            if(nums[i]<nums[i-1]){
                d++;
            }
            else{
                d=1;
            }

            l=max(l,max(in,d));



        }

        return l;
    }
};