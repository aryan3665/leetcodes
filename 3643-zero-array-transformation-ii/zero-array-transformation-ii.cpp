class Solution {
public:
    bool check(int mid,vector<int>&nums, vector<vector<int>>& queries){
        int n=nums.size();
        vector<int>sum(n,0);
        vector<int>pre(n+1,0);

        for(int i=0;i<mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            pre[l]+=val;;
            pre[r+1]-=val;
        }
        sum[0]=pre[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+pre[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i]>sum[i]){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0;
        int r=queries.size();
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums,queries)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};