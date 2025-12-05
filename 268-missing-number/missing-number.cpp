class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t=0;
        vector<bool>visited(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            visited[nums[i]]=1;
        }
        int ans=-1;
        while(ans==-1){
           if(visited[t]==0)ans=t;
           else t++; 
        }return ans;
    }
};