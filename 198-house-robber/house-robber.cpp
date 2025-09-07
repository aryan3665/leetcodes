class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int n2=0;
        int n3=0;
        int n1;

         

        for (int i = n - 1; i >= 0; i--) {
            int skip = n2;
            int steal = nums[i] + n3;
            n1 = max(steal, skip);
            n3=n2;
            n2=n1;
        }

        return n1;
    }
};
