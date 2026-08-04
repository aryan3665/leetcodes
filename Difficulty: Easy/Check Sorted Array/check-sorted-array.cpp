class Solution {
  public:
  bool solve(vector<int>&arr,int i){
      if(i==0)return 1;
      if(arr[i-1]>arr[i])return 0;
      return solve(arr,i-1);
     
  }
    bool isSorted(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n-1);
    }
};