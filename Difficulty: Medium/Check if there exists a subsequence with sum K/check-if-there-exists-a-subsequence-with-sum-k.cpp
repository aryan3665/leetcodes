class Solution {
  public:
  bool solve(vector<int>&arr,int n,int k,int i){
      if(k==0)return true;
      if(i==n||k<0)return false;
      
      
      //not take or take
     return solve(arr,n,k,i+1)||solve(arr,n,k-=arr[i],i+1);
  }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return solve(arr,n,k,0);
    }
};