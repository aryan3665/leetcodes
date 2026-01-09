class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int minlen = INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minlen=min(minlen,j-i+1);
                sum-=nums[i];
                i++;
            }

            j++;

        }
        return (minlen == INT_MAX ? 0 : minlen);
    }
};