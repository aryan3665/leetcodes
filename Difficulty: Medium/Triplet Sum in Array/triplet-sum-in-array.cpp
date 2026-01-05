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
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        sort(arr.begin(),arr.end());
       int n=arr.size();
       
       for(int i=0;i<n-2;i++){
           int find=target-(arr[i]);
           bool ans=twosum(arr,i+1,n-1,find);
           if(ans==true)return true;
       }
       return false;
    }
};