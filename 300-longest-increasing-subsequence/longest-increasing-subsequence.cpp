class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
  int n=nums.size();
        vector<int>t(n+1,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);
                }
            }
        }

int ans=INT_MIN;
        for(int i=0;i<t.size();i++){
            ans=max(ans,t[i]);
        }
        return ans;
    }
};