class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int lar=arr[0];
        int n=arr.size();
        int sec=INT_MIN;
        int i=0;
        while(i<n){
            
            if(arr[i]>lar){
                sec=lar;
                lar=arr[i];
            }
            
            if(arr[i]<lar&&arr[i]>sec){
                sec=arr[i];
            }
            
            
            
            
            
            
            i++;
        }
    return (sec==INT_MIN?-1:sec);
    }
};