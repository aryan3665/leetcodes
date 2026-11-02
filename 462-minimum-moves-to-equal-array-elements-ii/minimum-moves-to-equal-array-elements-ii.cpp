class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=nums[(n-1)/2];
        int diff=0;
        for(int i=0;i<n;i++){
            diff+=abs(nums[i]-mid);
        }

        return diff;
    }
};