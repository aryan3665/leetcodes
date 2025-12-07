class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
//kadens chacha algorith start karte hain yaha pe
int sum=0;
for(int i=0;i<n;i++){
    if(sum<0)sum=0;
    sum+=nums[i];
    maxi=max(sum,maxi);

}
return maxi;
    }
};
