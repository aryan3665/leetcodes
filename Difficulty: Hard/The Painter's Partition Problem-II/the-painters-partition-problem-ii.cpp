class Solution {
  public:
  bool isanswer(vector<int>&arr,int k,int mid){
      int painters=1;
      int size=0;
      for(int i=0;i<arr.size();i++){
          size+=arr[i];
          if(size>mid){
              painters++;
              size=arr[i];
          }
      }
      
      return painters<=k;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        //binary search on answer 
        int ans=-1;
        if(k>arr.size())return -1;
        int start=*max_element(arr.begin(),arr.end());
        int end=1e9;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isanswer(arr,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};