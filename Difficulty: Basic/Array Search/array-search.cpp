class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        int index=-1;
      
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==x){
            
                index=i;
                break;
            }
        }
      return index;
    
        
    }
};