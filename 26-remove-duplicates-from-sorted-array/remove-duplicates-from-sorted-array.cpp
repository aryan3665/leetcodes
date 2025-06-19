class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=i+1;
        while(j<nums.size()&&i<nums.size()-1){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
                j++;
            }
            else{
                j++;
            }
        }
        return i+1;
    }
};