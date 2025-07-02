class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int i=0;
        int j=0;
        int n=arr.size();
        int result=INT_MIN;
        map<int,int>mp;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                i++;
                
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};