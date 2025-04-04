class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int left=0;
      int right=n-1;
      int ans=-1;
      while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
          ans=mid;
          return ans;
            
        }
        else if(nums[left]<=nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        else{
             if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // Search in right half
                } else {
                    right = mid - 1;  // Search in left half
                }

        }
      }

        return ans;
      }
};
