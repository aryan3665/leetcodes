class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int low=0;
        int n=arr.size();
        int end=n-1;
        int ans=n;
        while(low<=end){
            int mid=low+(end-low)/2;
           
            if(arr[mid]>=target){
                ans=mid;
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};
