class Solution {
  public:
  
  void solve(vector<int>&arr,int i,vector<int>&ans,int sum){
      
      if(i==arr.size()){
          ans.push_back(sum);
          return;
      }
      
      
      
      //not taken
      solve(arr,i+1,ans,sum);
      //taken
      solve(arr,i+1,ans,sum+=arr[i]);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
       
        solve(arr,0,ans,0);
        return ans;
        
        
    }
};