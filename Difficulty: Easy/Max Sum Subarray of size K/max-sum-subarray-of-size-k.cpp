class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        
        int maxi=INT_MIN;
        int n=arr.size();
        int i=0;
        int j=0;
        int sum=0;
        while(j<n){
          
                sum+=arr[j];
             
           
             if((j-i+1)==k){
              
                maxi=max(maxi,sum);
                sum-=arr[i];
                i++;
             }
                j++;
            
        }
        return maxi;
    }
};