class Solution {
  public:
  bool solve(vector<int>&arr,int n){
      if(n==0)return 1;
      if(arr[n-1]>arr[n])return 0;
      return solve(arr,n-1);
     
  }
    bool isSorted(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n-1);
    }
};