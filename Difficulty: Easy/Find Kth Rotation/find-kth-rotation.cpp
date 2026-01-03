class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int l=0;
        int index=-1;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[r]>arr[mid]){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return (r<0)?0:r;
    }
};
