class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            bool flag=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]==0&&nums[j]!=0){
                    swap(nums[i],nums[j]);
                    
                }
            }
     
        }
    }
};