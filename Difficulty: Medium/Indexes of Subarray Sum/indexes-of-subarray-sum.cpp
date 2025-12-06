class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int>ans;
        map<int,int>mp;
        int n=arr.size();
        int pre=0;
        for(int i=0;i<n;i++){
            pre+=arr[i];
            mp[pre]=i+1;
            if(pre-target==0){
                ans.push_back(1);
                ans.push_back(i+1);
                return ans;
            }
            else if(pre>target){
                int ser=pre-target;
                if(mp.find(ser)!=mp.end()){
                    ans.push_back(mp[ser]+1);
                    ans.push_back(i+1);
                    return ans;
                }
            }
        }
        return {-1};
    }
};