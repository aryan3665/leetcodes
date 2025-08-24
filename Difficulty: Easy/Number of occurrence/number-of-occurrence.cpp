class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
          int n=nums.size();
        int first=-1;
        int last=-1;
        int start=0;
        int end=n-1;
        //first;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;

            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        end=n-1;
        start=0;
         while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                last=mid;
                start=mid+1;

            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(last==-1&&first==-1)return 0;
        

        return last-first+1;
    }
};
