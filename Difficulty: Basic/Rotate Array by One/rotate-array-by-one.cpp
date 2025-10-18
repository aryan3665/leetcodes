// User function Template for C++

class Solution {
  public:
void rev(vector<int>&arr,int i,int j){

      while(i<=j){
          swap(arr[i],arr[j]);
          i++;
          j--;
      }
  }
    void rotate(vector<int> &arr) {
        // code here
        int n=arr.size();
        rev(arr,0,n-2);
        rev(arr,0,n-1);
        
    }
};