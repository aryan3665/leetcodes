class Solution {
public:
    int search(vector<int>& nums, int target) {
       int result=-1;
       int low=0;
       int n=nums.size();
       int high=n-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target)return mid;
        //check kya left half sorted hai
        if(nums[low]<=nums[mid]){
            //check karo ki target uss sorted half me hai
            if(nums[low]<=target&&target<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        else{
            //mATlab right half sorted hai ek half to sorted hoga hi 

            //check karenge ki value kis part me hai 
            if(nums[mid]<=target&&target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
       }

       return -1; 
    }
};