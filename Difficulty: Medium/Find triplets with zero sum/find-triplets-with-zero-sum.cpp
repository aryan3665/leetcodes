class Solution {
  public:
  
  bool twosum(vector<int>&arr,int start,int end,int find){
     
     while(start<end){
      if((arr[start]+arr[end])==find)return true;
      else if((arr[start]+arr[end])>find)end--;
      else start++;
     }
     return false;
  }
    bool findTriplets(vector<int> &arr) {
        // code here
       sort(arr.begin(),arr.end());
       int n=arr.size();
       
       for(int i=0;i<n-2;i++){
           int find=0-(arr[i]);
           bool ans=twosum(arr,i+1,n-1,find);
           if(ans==true)return true;
       }
       return false;
    }
};