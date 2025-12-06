// User function template for C++
class Solution {
  public:
    /* Function to replace every element with the
    next greatest element */
    vector<int> nextGreatest(vector<int> arr) {
        // code here
        int n=arr.size();
         int tem=arr[n-1];
            arr[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            int pre=arr[i];
            arr[i]=max(tem,arr[i+1]);
            tem=pre;
            
        }
        return arr;
        
    }
};