class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;
        int j=1;
        while(j<nums.length){
            if(nums[j]>nums[i]){
                i++;
                int c=nums[i];
                nums[i]=nums[j];
                nums[j]=c;

            }
            j++;
        }

        return  i+1;
    }
}