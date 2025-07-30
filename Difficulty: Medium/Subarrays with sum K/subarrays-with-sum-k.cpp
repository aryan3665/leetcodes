class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
          int n =arr.size();
        map<int,int>mp;
        mp[0]=1;
        int presum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            presum+=arr[i];
            int remove=presum-k;
            cnt+=mp[remove];
            mp[presum]+=1;
        }
        return cnt;
        
    }
};