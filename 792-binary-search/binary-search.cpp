class Solution {
public:
int solve(int start,int end,vector<int>& nums, int target){
    if(start>end)return -1;

    int mid=start+(end-start)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        return solve(start,mid-1,nums,target);
    }
    else return solve(mid+1,end,nums,target);

}
    int search(vector<int>& nums, int target) {
        return solve(0,nums.size()-1,nums,target);
    }
};