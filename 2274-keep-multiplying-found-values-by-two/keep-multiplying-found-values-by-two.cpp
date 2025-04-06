class Solution {
public:
int search(vector<int>nums,int&original){
    int start=0;
    int end=nums.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==original){
            original=2*original;
            start=0;
            end=nums.size()-1;
        }
        else if(nums[mid]>original){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        
    }
    return original;
}
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
      return search(nums,original);
    }
};