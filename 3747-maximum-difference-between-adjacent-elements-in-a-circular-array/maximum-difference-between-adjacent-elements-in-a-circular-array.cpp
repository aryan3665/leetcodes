class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++){
            maxi=max(maxi,abs(nums[i]-nums[i-1]));
        }

        maxi=max(maxi,abs(nums[n-1]-nums[0]));
        return maxi;
    }
};