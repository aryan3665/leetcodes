class Solution {
public:
bool isanswer(vector<int>&nums,int mid,int threshold){
    int sum=0;

    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)nums[i]/mid);
    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        //binary search on answers 
        int l=1;
        int ans;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isanswer(nums,mid,threshold)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};