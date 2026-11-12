
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int ans1 = 1;
        int ans2 = 1;

        for (int i = 0; i < nums.length; i++) {
            int c1 = 1;
            int c2 = 1;

            for (int j = i + 1; j < nums.length; j++) {

                if (nums[j] > nums[j - 1]) {
                    ans2 = Math.max(ans2, c2);
                    c2 = 1;
                    c1++;
                }
                else if (nums[j] < nums[j - 1]) {
                    ans1 = Math.max(ans1, c1);
                    c1 = 1;
                    c2++;
                }
                else {
                    ans1 = Math.max(ans1, c1);
                    ans2 = Math.max(ans2, c2);
                    c1 = 1;
                    c2 = 1;
                }
            }

            ans1 = Math.max(ans1, c1);
            ans2 = Math.max(ans2, c2);
        }

        return Math.max(ans1, ans2);
    }
}
