class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int start=0;
        int end=arr.size()-1;
        int index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>x){
                end=mid-1;
            }
            else if(arr[mid]<=x){
                index=mid;
                start=mid+1;
            }
        }
        
        return index;
    }
};
