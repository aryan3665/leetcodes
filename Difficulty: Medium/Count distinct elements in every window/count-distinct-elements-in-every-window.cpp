class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int i=0;
        int n=arr.size();
        int j=0;
        map<int,int>mp;
        vector<int>ans;
        while(i<n&&j<n){
            mp[arr[j]]++;
            if((j-i+1)==k){
                ans.push_back(mp.size());
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};