class Solution {
  public:
  int f(vector<int>&arr,int i,int n,int&maxi){
      if(i==n-1){
          return max(maxi,arr[i]);
      }
      
      int a=arr[i];
      int k=f(arr,i+1,n,maxi);
      return max(a,k);
  }
    int largest(vector<int> &arr) {
        // code here
        //recursion 
        int maxi=INT_MIN;
        return f(arr,0,arr.size(),maxi);
    }
};
