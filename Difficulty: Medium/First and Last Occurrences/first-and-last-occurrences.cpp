class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        vector<int>ans;
        int l=-1;
        int r=n;
        while(r-l>1){
            int mid=(l+r)/2;
            //first index
            (arr[mid]<x)?l=mid:r=mid;
        }
        if(r!=n&&arr[r]==x){
            ans.push_back(r);
        }
        else{
            ans.push_back(-1);
        }
        
         l=-1;
         r=n;
          while(r-l>1){
            int mid=(l+r)/2;
            //first index
            (arr[mid]<=x)?l=mid:r=mid;
        }
        if(l!=-1&&arr[l]==x){
            ans.push_back(l);
        }
        else{
            ans.push_back(-1);
        }
        return ans;
    }
};