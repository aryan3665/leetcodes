class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int k=n-1;
        while(j<=k){
            if(nums[j]==2){
                swap(nums[k],nums[j]);
                k--;
            }
            else if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==1){
            j++;}
        }
    }
};