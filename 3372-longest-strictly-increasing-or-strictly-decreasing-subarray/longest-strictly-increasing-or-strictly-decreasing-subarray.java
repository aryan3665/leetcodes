class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int ans1 = 1;
        //increesing
        int c1 = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                c1++;
            } else {
                ans1 = Math.max(ans1, c1);
                c1 = 1;
            }
        }

        ans1=Math.max(ans1,c1);


        //decresing 
        int ans2 = 1;
        
        int c2 = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                c2++;
            } else {
                ans2 = Math.max(ans2, c2);
                c2 = 1;
            }
        }

          ans2=Math.max(ans2,c2);

return Math.max(ans1,ans2);
    }
}