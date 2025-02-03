class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int l1=1;
        int l2=1;
        int in=1;
        int d=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                in++;
                 l1=max(l1,in);
               
            }
            else{
               
                in=1;
            }
        }


             for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                d++;
                    l2=max(l2,d);
               
            }
            else{
            
                d=1;
            }
        }

        return max(l1,l2);
    }
};