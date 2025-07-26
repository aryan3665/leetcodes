class Solution {
  public:
  void merge(vector<int>&arr,int start,int mid,int end){
      vector<int>temp(end-start+1);
      int left=start;
      int right=mid+1;
      int index=0;
      while(left<=mid&&right<=end){
          if(arr[left]<=arr[right]){
              temp[index]=arr[left];
              index++;
              left++;
          }
          else{
              temp[index]=arr[right];
              index++;
              right++;
              
          }
      }
      while(left<=mid){
          temp[index]=arr[left];
          index++;
          left++;
      }
      
      while(right<=end){
          temp[index]=arr[right];
          index++;
          right++;
      }
      index=0;
      while(start<=end){
          arr[start]=temp[index];
          index++;
          start++;
      }
      
      
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l==r)return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};