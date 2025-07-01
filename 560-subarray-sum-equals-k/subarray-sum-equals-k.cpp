class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int cumm=0;
        mp[0]=1;
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cumm+=nums[i];
            if(mp.find(cumm-k)!=mp.end()){
                c+=mp[cumm-k];
            }
             mp[cumm]++;

        }
        return c;
    }
};