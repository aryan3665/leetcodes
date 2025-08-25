class Solution {
public:
    int findMin(vector<int>& nums) {
        //just pickup minimum from sorted half and eliminate that portion as now we will get answer in unsorted half only 
        int low=0;
        int n=nums.size();
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            //check which half is sorted
            //left half sorted
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
                //just stored minimum and elemenate this half

            }
            else{
                //right half sorted
                ans=min(ans,nums[mid]);
                high=mid-1;
                //just take minimum elemnt and move left
            }

        }
        return ans;
    }
};